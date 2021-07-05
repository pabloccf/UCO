#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char* argv[]){
    if(argc<2){
        fprintf(stderr, "Error, numero de argumentos no valido. Debe introducir el valor P\n");
        exit(EXIT_FAILURE);
    }

    int nhijos=atoi(argv[1]);
    int status;
    pid_t pid, chilpid;

    for (int i = 0; i < nhijos; i++){
        pid=fork();
        switch (pid){
        case -1:
            perror("Fork error\n");
            fprintf(stderr, "Errno value: %d", errno);
            exit(EXIT_FAILURE);

        case 0:
            break;
        
        default:
            sleep(3);
            chilpid=wait(&status);

            //while(pid==waitpid(-1, &status, WUNTRACED | WCONTINUED)){
                if(chilpid>0){
                    if(WIFEXITED(status)){
                        printf("Proceso padre %d, hijo con PID %d finalizado, status=%d\n", getpid(), pid, WEXITSTATUS(status));
                    }

                    else if(WIFSIGNALED(status)){
                        printf("Proceso padre %d, hijo con PID %d finalizado al recibir la señal %d\n", getpid(), pid, WTERMSIG(status));
                    }

                    else if(WIFSTOPPED(status)){
                        printf("Proceso padre %d, hijo con PID %d ha sido parado al recibir la señal %d\n", getpid(), pid, WSTOPSIG(status));
                    }

                    printf("El PID del padre es: %d, el status es: %d y la suma del ultimo digito del pid del padre con el estatus es: %d\n", getpid(), WEXITSTATUS(status), getpid()%10 + WEXITSTATUS(status));
                    exit(getpid()%10 + WEXITSTATUS(status));
                    

                }
            //}
            /*
            if(pid==(pid_t) -1 && errno== ECHILD){
                printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno=%d, definido como: %s\n", getpid(), errno, strerror(errno));
            }

            else{
                printf("Error en la invocacion del wait o waitpid. Valor de errno: %d, definido como: %s\n", errno, strerror(errno));
                exit(EXIT_FAILURE);
            }
            */
        }
    }
    
    exit(getpid()%10);  //Hallas el ultimo numero del pid del padre
}