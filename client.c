#include "minitalk.h"
int pid(char k,int num)
{
    num = num * 10 + (k - '0');
    return num;
}
void send_bits(int pid, char *msg)
{
    printf("==>%d\n", pid);
    t_tools tol;
    
    tol.i = 0;
    while (msg[tol.i])
    {
        tol.bit = 7;
        while (tol.bit >= 0)
        {
            if (msg[tol.i] >> tol.bit & 1)
                kill (pid, SIGUSR2);
            else    
                kill (pid, SIGUSR1);
            tol.bit--;
            usleep (200);
        }
        tol.i++;
    }
}
int main(int ac, char **av)
{
    t_tools tol;
    tol.i = 0;
    if (ac != 3)
        exit(write (1,"error",5));
    while (av[1][tol.i] != '\0')
    {
        if(av[1][tol.i]>= '0' && av[1][tol.i] <= '9')
            tol.pid = pid(av[1][tol.i], tol.pid);
        else
            exit(write (1,"error pid",9));
        tol.i++;
    }
    if (tol.pid <= 0)
        exit(write(1, "pid not good",12));
    send_bits(tol.pid,av[2]);
    return 0;
}