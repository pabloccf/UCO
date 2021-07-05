#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


void controlador_senal(int signal)
{
    printf("Capturada señal %d\n", signal);

    //Importante no poner aqui un exit porque si no terminara todo el proceso hijo y solo capturara la primera señal
}


int main()
{
    pid_t child_pid, wpid;
    int status;


    child_pid = fork();
    
    if (child_pid == -1) 
    {      /* fork() failed */
    perror("fork");
    exit(EXIT_FAILURE);
    }


    if (child_pid == 0) 
    {       
        printf("Soy el hijo con pid %d, mi padre tiene pid %d\n", getpid(), getppid());

        printf("Estoy esperando señales...\n");

        signal(SIGUSR1, controlador_senal);

        while(1){}

    } 
    else 
    {                    
        sleep(1);
        printf("Soy el padre y voy a comenzar a mandar señales.....\n");


        for(int i=0; i<3; i++)
        {
            kill(child_pid, SIGUSR1);
            sleep(1);
        }

        kill(child_pid, SIGKILL);
    
    }

    do 
    {
        wpid = waitpid(child_pid, &status, WUNTRACED | WCONTINUED);
        
        if (wpid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }


        if (WIFEXITED(status)) {
            printf("child exited, status=%d\n", WEXITSTATUS(status));


        } 
        else if (WIFSIGNALED(status)) 
        {
            printf("child killed (signal %d)\n", WTERMSIG(status));


        } 
        else if (WIFSTOPPED(status)) 
        {
            printf("child stopped (signal %d)\n", WSTOPSIG(status));
        } 
        else if (WIFCONTINUED(status)) 
        {
            printf("child continued\n");

        }

    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

    return 0;
}