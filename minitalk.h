#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>  //for write()
#include <signal.h>  //for kill(), struct sigaction,usleep()....
#include <stdlib.h>  //for exit()
#include <stdio.h> // for test

typedef struct s_tools
{
    int i;
    int bit;
    int pid;
}   t_tools;


void send_bits(int pid, char *msg);
int pid(char k,int num);
void print_pid(int pid);
void handler_message(int sig_msg, siginfo_t *info, void *nting);
#endif