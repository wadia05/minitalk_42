/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:38 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/19 10:02:39 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(int pid)
{
	if (pid > 9)
		print_pid(pid / 10);
	write(1, CYAN, sizeof(CYAN) - 1);
	write(1, &"0123456789"[pid % 10], 1);
	write(1, RESET, sizeof(RESET) - 1);
}

void	handler_message(int sig_msg, siginfo_t *info, void *nting)
{
	static char	chr;
	static int	cl_pid;
	static int	last_pros_id;
	static int	cont_bit = 7;

	cl_pid = info->si_pid;
	if (cl_pid != last_pros_id)
	{
		last_pros_id = cl_pid;
		cont_bit = 7;
		chr = 0;
	}
	if (sig_msg == SIGUSR2)
		chr |= (1 << cont_bit);
	cont_bit--;
	if (cont_bit == -1)
	{
		write(1, &chr, 1);
		cont_bit = 7;
		chr = 0;
	}
	(void)nting;
}

int	main(void)
{
	struct sigaction	sg;

	write(1, BLUE "PID : ", 6 + sizeof(BLUE) - 1);
	print_pid(getpid());
	write(1, "\n", 1);
	sg.sa_sigaction = handler_message;
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	while (1)
		pause();
	return (0);
}
