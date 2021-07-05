#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void imprimirPID(){
    printf("Mi PID es: %d\n", getpid());
}

int main(){
    signal(SIGUSR1, imprimirPID);
    printf("Mi PID es: %d\n", getpid());

    while(1){
        pause();
    }

    exit(EXIT_SUCCESS);
}