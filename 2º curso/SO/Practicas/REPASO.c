//**************************************************************************************************************************
//LAS LIBRERIAS NECESARIAS DE SABER PARA EL EXAMEN SON:

//LAS BASICAS
#include <stdio.h>
#include <stdlib.h>
//LAS ESPECIFICAS DE LOS TEMAS
#include <errno.h>  //SE USA SIEMPRE
#include <unistd.h> //EN PROCESOS
#include <sys/types.h>  //EN PROCESOS
#include <sys/wait.h>   //EN PROCESOS

#include <pthread.h>    //EN HEBRAS

#include <semaphore.h>  //EN SEMAFOROS
//PARA USAR SEÑALES
#include <signal.h>

//**************************************************************************************************************************

//PARA COMPILAR LOS PROGRAMAS EN LINUX SIEMPRE ES LA MISMA SECUENCIA:

    //gcc ejemplo.c -o ejemplo.exe (variables si fuese necesario)

//SI SE UTILIZAN HEBRAS DEBE AÑADIRSE AL FINAL "-lpthread":

    //gcc ejemplo.c -o ejemplo.exe -lpthread (variables si fuese necesario)

int main(){

//**************************************************************************************************************************
//TEMA 1: PROCESOS
//**************************************************************************************************************************

//PARA EMPEZAR DEBEMOS CREAR VARIABLES PARA ALAMECENAR LOS PID DE NUESTROS PROCESOS, ESTO SE HACE CON:
    
    pid_t pid,hijo_pid;
    
//DEBEREMOS CREAR PARA MAS ADELANTE ESPERAR A LOS PROCESOS UNA VARIABLE ENTERA STATUS:

    int status;

//**************************************************************************************************************************

//PARA INICIALIZAR UN PROCESO DEBEREMOS USAR UNA DELAS VARIABLES GENERADAS ANTERIORMENTE JUNTO A LA FUNCION FORK().
/*FORK DEVOLVERA:
    -1:SE HA PRODUCIDO UN ERROR.
    0:ESTAMOS EN UN PROCESO HIJO.
    DEFAULT/CUALQUIER OTRO VALOR SI ES EL PROCESO PADRE.
*/
    pid=fork();         //SE SUELE UTILIZAR UN SWITCH PARA EXAMINAR EL FORK.

//**************************************************************************************************************************

//PARA SABER EL PID DE UN PROCESO O EL PID DE EL PROCESO PADRE DE NUESTRO PROCESO UTILIZAREMOS DOS FUNCIONES GETPID,GETPPID:

    printf("Soy el proceso con PID: %d",getpid());
    printf("Soy el proceso creado por mi padre cuya PID es: %d",getppid());

//**************************************************************************************************************************

//EXISTEN DOS FUNCIONES QUE VAS A UTILIZAR POCO PERO TE LAS DEJO AQUI POR SI TE ENTRARAN. SON GETUID() y GETENV().

    //GETUID() DEVUELVE EL USUARIO QUE HA CREADO UN PROCESO, SI DENTRO DE ESEPROCESO LO LLAMAS SABRAS EL USUARIO:
    getuid();
    
    //GETENV SE UTILIZA PARA ESTABLECER EL ENTORNO DE TRABAJO DE TUS PROCESOS, SE UTILIZAN VARIABLES EN MAYUSCULAS.
    //CUANDO TE REFIERES A ESAS VARIABLES EN LA SHELL/CONSOLA DEBES ESCRIBIRLAS CON "$", EJEMPLO: $HOME.

    getenv(ejemplo); //DEBES METER COMO PARAMETRO UNA VARIABLE ESPECIAL CREADA CON ANTERIORIDAD.
    
    //¡¡¡¡¡¡ES MUY RARO QUE TE PONGA ALGO DE ESTAS DOS FUNCIONES!!!!!!

//**************************************************************************************************************************

//PARA LLAMAR A QUE SE EJECUTE UN PROCESO FUERA DE NUESTRO PROGRAMA SE UTILIZARAN LAS FUNCIONES EXECL y EXECV.

//ESTAS FUNCIONES A SU VEZ SE PUEDEN DESGLOSAR EN 3 CADA UNA:
/*
EXECL:
    
    1-EXECL(), 2- EXECLP(), 3-EXECLE().
EXECV:

    1-EXECV(), 2-EXECVP(), 3-EXECVE().
*/

//TODAS TIENEN SUS PARAMETROS TE RECOMIENDO MIRARLAS TANTO EN LA PRACTICA DE SO COMO EN MAN PARA ENTENDERLAS MEJOR:

    //https://moodle.uco.es/m2021/pluginfile.php/10789/mod_resource/content/5/Practica1%20-%20Procesos%20y%20seniales.pdf

//**************************************************************************************************************************

//PARA ESPERAR A QUE TERMINE DE EJECUTARSE UN PROCESO SE INVOCA LA FUNCION WAIT(). EN ESTA PASAREMOS POR REFERENCIA STATUS.
//ESTA IRA HILADA A UNA SERIE DE CONDICIONES QUE DEBERAN ESTABLECERSE.

    hijo_pid=wait(&status);

//COMO YA HEMOS CITADO AL INVOCAR UN WAIT DEBEMOS ESTABLECER UNA SERIE DE CONDICIONES QUE DEBERAN APRENDERSE:

    if(hijo_pid>0){         //DEBE SER EXTRICTAMENTE MAYOR QUE 0 PUESTO QUE SI NO SIGNIFICARIA QUE LA ESPERA DEL PROCESO HA DADO FALLO.

        //PRIMERO DEBEMOS ESTABLECER UNA CONDICION DE QUE EXISTE EL PROCESO HIJO QUE SE ESTA ESPERANDO:
        if(WIFEXISTED(status)) printf("El hijo %d existe, estado: %d",hijo_pid,WEXITSTATUS(status));
        //LA SEGUNDA CONDICION ES QUE EL PROCESO NO HAYA MUERTO, ES DECIR NO SE HAYA ELIMINADO:
        if(WIFSIGALED(status)) printf("El hijo %d murio(signal %d",hijo_pid,WTERMSIG(status));
        //LA ULTIMA CONDICION ES QUE EL PROCESO NO SE HAYA PARADO:
        if(WIFSTOPPED(status)) printf("El hijo %d ha parado(signal %d",hijo_pid,WSTOPSIG(status));
    }
    //SI TODO FUESE BIEN NINGUNO DE ESTOS MENSAJES APARECERIA.
    else{                   //DEBEMOS HACER UN ELSE POR SI ES MENOR IGUAL A 0 POR LO QUE LA FUNCION HABRIA FALLADO:
        //REPORTARIAMOS EL ERROR CON ERRNO, APROVECHO PARA ENSEÑAR A USAR ERRNO:
        //HAY DOS MANERAS,
        
        //PRIMERA: 
        perror("wait error.");              //UTILIZAMOS PERROR PARA INDICAR QUE ERROR ES.
        printf("errno value: %d",errno);    //UTILIZAMOS UN PRINTF PARA INDICAR EL VALOR DE ERRNO.
        exit(EXIT_FAILURE);                 //SALIMOS DEL PROGRAMA CON EXIT_FAILURE.

        //SEGUNDA:
        printf("Error en la invocacion del wait. Codigo de error: %d",errno);   //UTILIZAR UN PRINTF CON UNA PEQUEÑA DESCRIPCION Y EL VALOR DE ERRNO.
        exit(EXIT_FAILURE);                                                     //SALIMOS DEL PROGRAMA CON EXIT_FAILURE.
    }

//**************************************************************************************************************************

/*PARA SALIR DE LOS PROCESOS NORMALMENTE SE UTILIZA EL RETURN 0, AHORA COMO TAMBIEN UTILIZAMOS EXIT(EXIT_FAILURE), 
PARA SALIR TAMBIEN PODREMOS UTILIZAR EXIT(EXIT_SUCCES) O EXIT():*/

    return 0;           //SALE CON NORMALIDAD.
    exit(0);             //SALE CERRANDO Y ELIMINANDO TODO EL PROCESO.
    exit(EXIT_SUCCESS); //SALE IGUAL QUE EXIT() PERO SIN VACIAR LOS BUFFERS DE SALIDA.

    //PARA SALIR DE UN PROCESO EL CUAL NO QUIERAS QUE SE ELIMINEN LOS DATOS UTILIZA ESTA ULTIMA.
    //EJEM:SI HAY UN WAIT ESPERANDO A UN HIJO EN EL HIJO UTILIZA EXIT SUCCESS PARA QUE LA INFORMACION QUE DEVUELVE NO SE ELIMINE.

//**************************************************************************************************************************

//VAMOS A VER LAS SEÑALES Y SUS TIPOS:

/*PARA LAS SEÑALES SE UTILIZAN MUCHO LAS MACROS COMO PRO EJEMPLO:
    
    SIGINT-AL PULSAR ctrl+c SE TERMINA EL PROCESO.
    SIGFPE-SI EN UN PROCESO OCURRE UN ERROR DE COMA FLOTANTE(ejem:division por 0) SE TERMINA EL PROGRAMA.
    SIGTERM y SIGKILL- AMBOS ACABAN EL PROGRAMA, EL PRIMERO TE DEJA UN POCO DE CONTROL TODAVIA SOBRE ESTE MIENTAS QUE EL SEGUNDO NO.
    SIGSTOP y SIGCONT- PARA PARAR EL PROGRAMA Y HACERLO CONTINUAR.
    SIGALRM- PARA ESTABLECER UNA "ALARMA", CUENTA ATRAS.
    SIGUSR1 y SIGUSR2-DOS MACROS PARA QUE LAS RELLENES TU MISMO.
*/
//PARA LLAMAR A CUALQUIER SEÑAL SE UTILIZARA LA FUNCION SIGNAL(), EN ESTA DEBERAS INTRODUCIR LA MACRO Y COMO QUIERES QUE FUNCIONE.
        //SI DE SEGUNDO PARAMETRO LE PONES "SIG_DLF"", LA SEÑAL VA A ACTUAR CON NORMALIDAD.
        //SI DE SEGUNDO PARAMETRO LE PONES "SIG_ING", LA SEÑAL VA A SER TRATADA DE UNA MANERA QUE TUUU DEBERAS HABER PREPARADO CON ANTERIORIDAD¿¿COMOO??->

        /*SI QUIERES QUE UNA SEÑAL HAGA ALGO QUE TU QUIERES ESTABLECER, DEBERAS CREAR UN "MANEJADOR DE SEÑAL",
        ES DECIR UNA FUNCION cotrolador() QUE HAGA LO QUE TU QUIERAS.*/

        //EJEMPLOS:
/*1*/   signal(SIGINT,SIG_DFL);

/*2*/   void controlador(...){
            ...
            ...
        }
            |
            |
            |
            \/
        signal(SIGINT,controlador());
//-------------------------------------------------------------

//UTILIZAREMOS LA FUNCION KILL() PARA ENVIAR SEÑALES A PROCESOS:

        kill(pid,SIGKILL);  //ENVIARA LA SEÑAL SIGKILL AL PROCESO QUE TENGA ESA PID.

//-------------------------------------------------------------

//TAMBIEN PODREMOS ESTABLECER UNA ALARMA LO CUAL PUEDE SER MUY UTIL CUANDO QUIERAS QUE SE ACTVEN COSAS EN MOMNETOS DETERMINADOS.
//SE UTILIZA ALARM():
        alarm(10); //DEBEMOS PASAR COMO PARAMETRO EL NUMERO DE SEGUNDOS EN EL QUE QUEREMOS QUE "SUENE".

    //¡¡¡¡¡NUNCA ACTIVES DOS ALARMAS A LA VEZ PORQUE LA PRIMERA SE TE VA A ELIMINAR!!!!!

//**************************************************************************************************************************
//TEMA 2: HILOS 
//**************************************************************************************************************************

//PARA CREAR UNA HEBRA LO PRIMERO QUE TENEMOS QUE HACER ES DEFINIR LAS VARIABLES QUE NOS SERVIRAN PARA CREARLA:

    pthread_t ejemplo,pthread[5],Lo_que_quieras;

//**************************************************************************************************************************

//A CONTINUACION VAMOS A EMPLEAR LA FUNCION CORRESPONDIENTE PARA CREEARLA:

    pthread_create(&ejemplo,NULL,ejemplo_de_funcion(),NULL);
    /*
    1ºPARAMETRO: La definicion de la hebra que se quiere crear.
    2ºPARAMETRO: Los atributos de la hebra, ahora mismo pon siempre NULL.
    3ºPARAMETRO: La rutina a la que quieres llamar, es decir la funcion que va a realizar la hebra(es un puntero a void(void*)).
    4ºPARAMETRO: Los parametros que quieres pasarle a la hebra,si no quieres pasar nada-NULL, si es una variable global-NULL, sino pasa lo que necesites.
    */

   //DEBEMOS INTRODUCIR UN IF Y SABER SI SE HA CREADO BIEN O NO.

//**************************************************************************************************************************

//PARA ESPERAR A QUE ACABE UNA HEBRA UTILIZAREMOS LA SIGUIENTE FUNCION:

    pthread_join(ejemplo,NULL);
    /*
    1ºPARAMETRO: La hebra a la que esperamos que acabe.
    2ºPARAMETRO: Lo que nos tiene que devolver la hebra, si deuelve un dato metele una variable, si no devuelve nada-NULL.
    */

    //DEBEMOS INTRODUCIR UN IF Y SABER SI SE HA ESPERADO BIEN O NO.

//**************************************************************************************************************************

//PARA TERMINAR UNA HEBRA Y QUE NO SE ELIMINEN TODOS LOS DATOS O SE CIERRE MAL UTILIZAREMOS:
    
    pthread_exit(NULL);
    //PARAMETRO: Si devuelve algo o no;

//**************************************************************************************************************************

//EXISTEN 3 FUNCIONES MAS DE HEBRAS QUE POR SI ACASO VOY A AÑADIR:

//PTHREAD_SELF: DEVUELVE INFORMACION DEUNA HEBRA ENTRE OTRAS SU ID.
    
    pthread_self();

//PTHREAD_DETACH: CUANDO NO NOS INTERESE NADA QUE DEVUELVA LA HEBRA PODEMOS LIBERAR TODOS LOS DATOS CON ESTA FUNCION.

/*CUANDO LA HEBRA ACABA SE QUEDA ESPERANDO UN JOIN Y SI ESTE NUNCA LLEGA SE ELIMINA CUANDO ACABE EL PROGRAMA. 
SI NO NECESITAMOS QUE DEVUELVA NADA ESA HEBRA CUANDO ACABE PODEMOS LIBERAR TODOS LOS DATOS CON ESTA FUNCION.

IMPORTANTE: SI UTILIZAS ESTA FUNCION NO PUEDE HABER UN JOIN QUE ESPERE ESA HEBRA.*/

    pthread_detach();

//PTHREAD_KILL: ASI PODEMOS MANDAR SEÑALES A LAS HEBRAS COMO YA VIMOS ANTES EN PROCESOS:

    pthread_kill(ejemplo,SIGKILL);
    //1ºPARAMETRO: La hebra.
    //1ºPARAMETRO: El macro de la señal que quieres mandar.

//**************************************************************************************************************************
//TEMA 3: SEMAFOROS
//**************************************************************************************************************************

//LAS HEBRAS TIENEN SU PROPIO SISTEMA DE SEMAFOROS Y SINO SIEMPRE PODEMOS UTILIZAR EL PREDEFINIDO EN C:

//MUTEX: SEMAFOROS PROPIOS DE LAS HEBRAS.

//---------------------------------------------------------------

//PARA CREAR UN MUTEX PRIMERO HAY QUE DEFINIR LAS VARIABLES QUE SE VAN A QUERER UTILIZAR, LUEGO SE CREARA CON SU FUNCION
    
    pthread_mutex_t mutex;
    pthread_mutex_init(mutex,NULL); //EL PRIMER PARAMETRO ES LA DEFINICION Y EL SEGUNDO EL TIPO DE MUTEX QUE QUEREMOS.
    //LOS TIPOS DE MUTEX SON 3: NORMAL(NULL), RECURSIVO Y ERRORCHECK Y CADA UNO TIENE SU MACRO.

//EXISTE UNA SEGUNDA MANERA DE CREAR UN MUTEX DEL TIRON QUE ES ASI:

    pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

//¡¡¡¡¡¡LOS MUTEX SE DEFINEN EN VARIABLES GLOBALES, NO EN EL MAIN!!!!!!!

//SI FALLA DEVUELVE 0, TENERLO EN CUENTA.

//---------------------------------------------------------------

//PARA BLOQUEAR UNA SECCION CRITICA UTILIZAREMOS LA SIGUIENTE FUNCION:

    pthread_mutex_block(&mutex);    //DE PARAMETRO PASAMOS NUESTRO MUTEX.

//---------------------------------------------------------------

//PARA DESBLOQUEAR UNA SECCION CRITICA UTILIZAREMOS LA SIGUIENTE FUNCION:

    pthread_mutex_unblock(&mutex);    //DE PARAMETRO PASAMOS NUESTRO MUTEX.

//---------------------------------------------------------------

//PARA DESTRUIR UN MUTEX SE UTILIZARA LA SIGUIENTE FUNCION:

    pthread_mutex_destroy(&mutex);
    //SI ESTA BLOQUEADO EL MUTEX AL ELIMINARLO SE PETA EL PROGRAMA.

//**************************************************************************************************************************

//SEMAFOROS GENERALES

//---------------------------------------------------------------

//PARA CREAR UN SEMAFORO DEBEMOS DEFINIRLO PRIMERO IGUAL QUE EL MUTEX:

    sem_t sem;

//UNA VEZ DEFINIDO SE INICIALIZA CON:

    sem_init(sem,0,1);
    /*
    1ºPARAMETRO: El semaforo.
    2ºPARAMETRO: Entero que determina si este semaforo solo puede ser utilizado por hilos de este proceso(si es asi es 0).
    3ºPARAMETRO: valor inicial del semaforo.
    */

//---------------------------------------------------------------

//PARA BLOQUEAR UN SEMAFORO DEBEMOS LLAMAR A LA SIGUIENTE FUNCION:

    sem_wait(&sem);     //DE PARAMETRO EL SEMAFORO.

//---------------------------------------------------------------

//PARA DESBLOQUEAR UN SEMAFORO DEBEMOS LLAMAR A LA SIGUIENTE FUNCION:

    sem_post(&sem);     //DE PARAMETRO EL SEMAFORO.

//---------------------------------------------------------------

//PARA DESTRUIR UN SEMAFORO SE UTILIZA:

    sem_destroy(&sem);      //DE PARAMETRO EL SEMAFORO.
    //SI ESTA BLOQUEADO EL SEMAFORO AL ELIMINARLO SE PETA EL PROGRAMA.

}
//**************************************************************************************************************************
//Muchas gracias por mirar este resumen de las funciones dadas en sistemas operativos.
//Realizada por Pablo Ibañez Fdez-Delgado.
//**************************************************************************************************************************