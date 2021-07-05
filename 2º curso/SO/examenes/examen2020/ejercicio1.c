#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe introducir un numero\n");
        exit(EXIT_FAILURE);
    }

    int status;
    pid_t pid, id;
    int numero=atoi(argv[1]);

    for (int i = 0; i < 2; i++){
        pid=fork();
        
        switch (pid){
        case -1:
            perror("Fork error\n");
            fprintf(stderr, "Errno value: %d", errno);
            exit(EXIT_FAILURE);

        case 0:
            if(i==0){
                printf("Soy el hijo con PID %d, mi padre tiene el PID %d y voy a calcular el factorial de %d...\n", getpid(), getppid(), numero);
                int factorial=1;
                for (int j = 2; j <= numero; j++){
                    factorial *= j;
                }

                printf("Soy el hijo %d, mi padre es %d y el factorial de %d es %d\n", getpid(), getppid(), numero, factorial);
                exit(EXIT_SUCCESS);
            }

            else if(i==1){
                printf("Soy el hijo %d, mi padre es %d y voy a abrir la calculadora...\n", getpid(), getppid());
                execlp("gnome-calculator", "gnome-calculator", NULL);
                exit(EXIT_SUCCESS);
            }

        default:
            id=wait(&status);
            if(id>0){
                if(WIFEXITED(status)){
                    printf("Padre %d, ha finalizado el hijo %d con el estado %d\n", getpid(), pid, WEXITSTATUS(status));
                }

                else if(WIFSIGNALED(status)){
                    printf("El hijo con PID %d ha salido recibiendo una señal: %d\n", pid, WTERMSIG(status));
                }

                else if(WIFSTOPPED(status)){
                    printf("El hijo con PID %d ha sido parado recibiendo una señal: %d\n", pid, WSTOPSIG(status));
                }
            }

            else{
                if(errno==ECHILD){
                    printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno= %d, definido como: %s\n", getpid(), errno, strerror(errno));
                    exit(EXIT_SUCCESS);
                }

                else{
                    perror("Wait error\n");
                    fprintf(stderr, "Errno value: %d", errno);
                    exit(EXIT_FAILURE);
                }
            }
        }                
    }

    exit(EXIT_SUCCESS);
}