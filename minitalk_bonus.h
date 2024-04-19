/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:02:55 by wait-bab          #+#    #+#             */
/*   Updated: 2024/04/19 10:02:56 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h> //for kill(), struct sigaction,usleep()....
# include <stdlib.h> //for exit()
# include <unistd.h> //for write()

// colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef struct s_tools
{
	int	i;
	int	bit;
	int	pid;
}		t_tools;

// client
void	send_bits(int pid, char *msg);
void	msg_back(int sig);
void	send_sig(char k, int bit, int pid);
int		pid(char k, int num);

// server
void	print_pid(int pid);
void	handler_message(int sig_msg, siginfo_t *info, void *nting);
#endif