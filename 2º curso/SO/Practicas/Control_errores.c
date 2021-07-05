#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

if(id>0){  //Empieza el control de errores
    /*
    EN CUALQUIERA DE ESTAS SEÑALES PUEDES PONER LA FRASE QUE TE DIGA EN EL ENUNCIADO
    */
    if(WIFEXITED(status)){
        printf("El hijo con PID %i ha salido con estado: %i\n",pid, WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status)){
        printf("Proceso padre %d, hijo %d finalizado al recibir la señal %d\n", getpid(), pid, WTERMSIG(status));
    }
    else{
        printf("El hijo con PID %i ha sido parado con una señal: %i\n",pid, WSTOPSIG(status));
    }
}

else{
    if(errno==ECHILD){
        printf("Proceso padre %d, no hay mas hijos que esperar. Valor de errno= %d, definido como: %s\n", getpid(), errno, strerror(errno));
        exit(EXIT_SUCCESS);
    }

    else{
        fprintf(stderr, "El proceso padre no ha esperado a que acabe el hijo. Valor de errno= %d, definido como %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
}  //Termina el control de errores