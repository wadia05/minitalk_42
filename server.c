#include "minitalk.h"

int cont_bit = 7;

void print_pid(int pid)
{
    if (pid > 9)
        print_pid(pid/10);
    write(1, &"0123456789"[pid%10], 1);
}

void handler_message(int sig_msg, siginfo_t *info, void *nting)
{
    static char chr;
    static int cl_pid;
    static int last_pros_id;

    cl_pid = info->si_pid;
    if (cl_pid != last_pros_id) // if cl_pid = last_pros then we are in the same message
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

int main()
{
    struct sigaction sg;

    print_pid(getpid());
    write (1,"\n",1);
    sg.sa_sigaction = handler_message;
    sg.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sg, NULL);
    sigaction(SIGUSR2, &sg, NULL);
    while (1)
        pause();
    return 0;
}
