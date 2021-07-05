#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    if(argc<3){
        fprintf(stderr,"Numero de argumentos no valido. Introduzca dos numeros.\n");
        exit(EXIT_FAILURE);
    }
    
    int status;
    pid_t pid;
    for(int i=0;i<2;i++){
        switch (fork()){
        case -1: //Error
            perror("Fork error");
            fprintf(stderr,"errno: %i\n",errno);
            exit(EXIT_FAILURE);
        
        case 0: //Hijo
            if(i==0){
                execlp("./factorial", "./factorial", argv[1], NULL);
            }

            if(i==1){
                execlp("./factorial", "./factorial", argv[2], NULL);
            }
            
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < 2; i++){ //Padre
        pid=wait(&status);
        if(pid>0){
            if(WIFEXITED(status)){
                printf("El hijo con PID %i ha salido con estado: %i\n",pid, WEXITSTATUS(status));
            }
            else if(WIFSIGNALED(status)){
                printf("El hijo con PID %i ha terminado con señal: %i\n",pid, WTERMSIG(status));
            }
            else if(WIFSTOPPED(status)){
                printf("El hijo con PID %i ha sido parado con señal: %i\n",pid, WSTOPSIG(status));
            }
        }
        else{
            fprintf(stderr,"Error en la llamada a la funcion wait\n");
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}