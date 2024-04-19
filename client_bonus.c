#include "minitalk_bonus.h"
int pid(char k,int num)
{
    num = num * 10 + (k - '0');
    return num;
}
void msg_back(int sig) 
{
    if (sig == SIGUSR2)
        write(1, GREEN"Message Received\n", 17 + sizeof(GREEN) -1);
}

void send_sig(char k,int bit,int pid)
{
    while (bit >= 0)
    {
        if (k >> bit & 1)
            kill (pid, SIGUSR2);
        else    
            kill (pid, SIGUSR1);
        bit--;
        usleep (90);
    }
}
void send_bits(int pid, char *msg)
{
    t_tools tol;
    
    tol.i = 0;
    while (msg[tol.i])
    {
        tol.bit = 7;
        send_sig(msg[tol.i],tol.bit,pid);
        tol.i++;
    }
    tol.bit = 7;
    send_sig('\0', tol.bit, pid);

}
int main(int ac, char **av)
{
    t_tools tol;
    tol.i = 0;
    if (ac != 3)
        exit (write(2, RED"ERROR ARGUMENT\n", 15 + sizeof(RED)-1));
    while (av[1][tol.i] != '\0')
    {
        if(av[1][tol.i]>= '0' && av[1][tol.i] <= '9')
            tol.pid = pid(av[1][tol.i], tol.pid);
        else
            exit(write (2,RED"ERROR PID FORMAT\n",17+sizeof(RED)-1));
        tol.i++;
    }
    if (tol.pid <= 0)
        exit(write(2, YELLOW"PID NOT EXIST\n", 14+sizeof(YELLOW)-1));
    signal(SIGUSR2, msg_back);
    send_bits(tol.pid,av[2]);
    return 0;
}
