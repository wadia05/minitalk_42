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

#endif