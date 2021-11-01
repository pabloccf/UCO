#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include<signal.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#include "funciones.h"


#define MSG_SIZE 350
#define MAX_CLIENTS 50


/*
 * El servidor ofrece el servicio de un chat
*/

void manejador(int signum);
void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]);



int main(){
   

	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int sd, new_sd;
	struct sockaddr_in sockname, from;
	char buffer[MSG_SIZE];
	socklen_t from_len;
	fd_set readfds, auxfds;
	int salida;
	int arrayClientes[MAX_CLIENTS];
	int numClientes = 0;
   	//contadores
	int i,j,k;
	int recibidos;
   	char identificador[MSG_SIZE];
    
    int on, ret;

    iniciarArrays();
    srand(time(NULL));
    
	/* --------------------------------------------------
		Se abre el socket 
	---------------------------------------------------*/
  	sd = socket (AF_INET, SOCK_STREAM, 0);
	if(sd == -1){
		perror("No se puede abrir el socket cliente\n");
    	exit (1);	
	}
    
    // Activaremos una propiedad del socket para permitir· que otros
    // sockets puedan reutilizar cualquier puerto al que nos enlacemos.
    // Esto permite· en protocolos como el TCP, poder ejecutar un
    // mismo programa varias veces seguidas y enlazarlo siempre al
   	// mismo puerto. De lo contrario habrÌa que esperar a que el puerto
    // quedase disponible (TIME_WAIT en el caso de TCP)
    on=1;
    ret = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));



	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2050);
	sockname.sin_addr.s_addr =  INADDR_ANY;

	if (bind (sd, (struct sockaddr *) &sockname, sizeof (sockname)) == -1){
		perror("Error en la operación bind");
		exit(1);
	}
	

   	/*---------------------------------------------------------------------
		Del las peticiones que vamos a aceptar sólo necesitamos el 
		tamaño de su estructura, el resto de información (familia, puerto, 
		ip), nos la proporcionará el método que recibe las peticiones.
   	----------------------------------------------------------------------*/
	from_len = sizeof(from);


	if(listen(sd,1) == -1){
		perror("Error en la operación de listen");
		exit(1);
	}
    
	//Inicializar los conjuntos fd_set
    FD_ZERO(&readfds);
    FD_ZERO(&auxfds);
    FD_SET(sd,&readfds);
    FD_SET(0,&readfds);
    
   	
    //Capturamos la señal SIGINT (Ctrl+c)
    signal(SIGINT,manejador);
    
	/*-----------------------------------------------------------------------
		El servidor acepta una petición
	------------------------------------------------------------------------ */
		while(1){
            
            //Esperamos recibir mensajes de los clientes (nuevas conexiones o mensajes de los clientes ya conectados)
            
            auxfds = readfds;
            
            salida = select(FD_SETSIZE,&auxfds,NULL,NULL,NULL);
            
            if(salida > 0){
                for(i=0; i<FD_SETSIZE; i++){
                    
                    //Buscamos el socket por el que se ha establecido la comunicación
                    if(FD_ISSET(i, &auxfds)) {
                        
                        if(i==sd){
                            
                            if((new_sd = accept(sd, (struct sockaddr *)&from, &from_len)) == -1){
                                perror("Error aceptando peticiones");
                            }

                            else{
                                if(numClientes < MAX_CLIENTS){
                                    arrayClientes[numClientes] = new_sd;
                                    numClientes++;
                                    FD_SET(new_sd,&readfds);
                                
                                    strcpy(buffer, "Bienvenido al Juego de la Ruleta\n");
                        
                                    send(new_sd,buffer,sizeof(buffer),0);
                                }

                                else{
                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer,"Demasiados clientes conectados\n");
                                    send(new_sd,buffer,sizeof(buffer),0);
                                    close(new_sd);
                                }
                            }
                        }

                        else if(i==0){
                            //Se ha introducido información de teclado
                            bzero(buffer, sizeof(buffer));
                            fgets(buffer, sizeof(buffer),stdin);
                            
                            //Controlar si se ha introducido "SALIR", cerrando todos los sockets y finalmente saliendo del servidor. (implementar)
                            if(strcmp(buffer,"SALIR\n")==0){
                                for (j = 0; j < numClientes; j++){
						            bzero(buffer, sizeof(buffer));
						            strcpy(buffer,"Desconexión servidor\n"); 
                                    send(arrayClientes[j],buffer , sizeof(buffer),0);
                                    close(arrayClientes[j]);
                                    FD_CLR(arrayClientes[j],&readfds);
                                }

                                close(sd);
                                exit(-1);
                            }
                            //Mensajes que se quieran mandar a los clientes (implementar) 
                        }

                        else{
                            bzero(buffer,sizeof(buffer));
                            
                            recibidos = recv(i,buffer,sizeof(buffer),0);
                            
                            if(recibidos > 0){
                                
                                if(strcmp(buffer,"SALIR\n")==0){
                                    salirCliente(i,&readfds,&numClientes,arrayClientes);
                                    

                                    if(players[i].state==JUGANDO){
                                        int j = players[i].game;
                                        games[j].state = INACTIVA;
                                        int otro_jugador = games[j].players[0];
                                        if(games[j].players[0]==i){
                                            otro_jugador = games[j].players[1];
                                        }

                                        players[otro_jugador].state = INICIAR_PARTIDA;
                                        games[j].players[0]=-1;
                                        games[j].players[1]=-1;

                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"+Ok. Ha salido el otro jugador. Finaliza la partida.\n");
                                        send(otro_jugador,buffer,sizeof(buffer),0);
                                    }

                                    players[i].state = USUARIO; //volvemos a poner a los jugadores a su estado inicial

                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer,"+Ok. Desconexión procesada.\n");
                                    send(i,buffer,sizeof(buffer),0);
                                }
                                /************************************************************************************************/

                                else if(strncmp(buffer,"USUARIO",7)==0){
                                    if(players[i].state!=USUARIO && players[i].state!=PASSWORD){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. Debe no estar logueado\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else{
                                        char user[100];
                                        strcpy(user,&buffer[8]);
                                        user[strlen(user)-1]='\0';  //ELIMINO EL \N DE LA CADENA
                                        if(comprobarUsuario(user)){
                                            players[i].state = PASSWORD;
                                            strcpy(players[i].name,user);
                                            bzero(buffer,sizeof(buffer));
                                            strcpy(buffer,"+Ok. Usuario correcto.\n");
                                            send(i,buffer,sizeof(buffer),0);
                                        }

                                        else{
                                            bzero(buffer,sizeof(buffer));
                                            strcpy(buffer,"-Err. Usuario incorrecto.\n");
                                            send(i,buffer,sizeof(buffer),0);
                                        }
                                    }
                                }

                                else if(strncmp(buffer,"PASSWORD",8)==0){
                                    if(players[i].state!=PASSWORD){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. Debe introducir previamente un nombre de usuario correcto.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else{
                                        char password[100];
                                        strcpy(password,&buffer[9]);
                                        password[strlen(password)-1]='\0';
                                        if(comprobarContrasena(players[i].name,password)){
                                            players[i].state = INICIAR_PARTIDA;
                                            bzero(buffer,sizeof(buffer));
                                            strcpy(buffer,"+Ok. Usuario validado.\n");
                                            send(i,buffer,sizeof(buffer),0);
                                        }

                                        else{
                                            bzero(buffer,sizeof(buffer));
                                            strcpy(buffer,"-Err. Error en la validación.\n");
                                            send(i,buffer,sizeof(buffer),0);
                                        }
                                    }
                                }

                                else if(strncmp(buffer,"REGISTRO",8)==0){
                                    int posicionNombre=-1, posicionPassword=-1;
                                    for (int i = 0; i < strlen(buffer); i++){
                                        if(buffer[i]=='-' && buffer[i+1]=='u'){
                                            posicionNombre = i+3;
                                        }

                                        else if(buffer[i]=='-' && buffer[i+1]=='p'){
                                            posicionPassword = i+3;
                                        }
                                    }

                                    char* nombre = buffer + posicionNombre;
                                    nombre = strtok(nombre," ");
                                    char* password = buffer + posicionPassword;
                                    password[strlen(password)-1]='\0';
                                    
                                    if(nuevoUsuario(nombre,password)){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"+Ok. Registro correcto.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else{
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. Error en el registro.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }
                                }

                                else if(strncmp(buffer,"INICIAR-PARTIDA",15)==0){
                                    if(players[i].state!=INICIAR_PARTIDA){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. Debe estar validado.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else{
                                        int x = buscarPartida(i);
                                        if(x>=0){
                                            if(games[x].state==ACTIVA){
                                                
                                                obtenerRefran(games[x].saying);

                                                for (int m = 0; m < strlen(games[x].saying); m++){
                                                    if(games[x].saying[m]!=' ' && games[x].saying[m]!=','){
                                                        games[x].panel[m] = '_';
                                                    }
                                                    
                                                    else{
                                                        games[x].panel[m] = games[x].saying[m];
                                                    }
                                                }    

                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+OK. Empieza la partida. Turno del otro jugador. FRASE: %s\n",games[x].panel);
                                                send(i,buffer,sizeof(buffer),0);

                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+OK. Empieza la partida. Turno de partida. FRASE: %s\n",games[x].panel);
                                                send(games[x].players[0],buffer,sizeof(buffer),0);

                                                players[i].state = JUGANDO;
                                                players[games[x].players[0]].state = JUGANDO;

                                                printf("%s\n",games[x].saying);
                                            }

                                            else{
                                                bzero(buffer,sizeof(buffer));
                                                strcpy(buffer,"+OK. Petición recibida. Quedamos a la espera de más jugadores.\n");
                                                send(i,buffer,sizeof(buffer),0);
                                            }
                                        }

                                        else{
                                            bzero(buffer,sizeof(buffer));
                                            strcpy(buffer,"-Err. No hay partidas disponibles.\n");
                                            send(i,buffer,sizeof(buffer),0);
                                        }
                                    }
                                }
                                
                                else if(strncmp(buffer,"CONSONANTE",10)==0){
                                    int turno = games[players[i].game].turn;
                                    if(games[players[i].game].players[turno]!=i){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No es su turno.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else if(players[i].state == JUGANDO){
                                        char consonante = buffer[11];
                                        int veces = buscarConsonante(players[i].game,consonante);
                                        if(veces==0){
                                            bzero(buffer,sizeof(buffer));
                                            sprintf(buffer,"+Ok. %c aparece %d veces. FRASE: %s\n",consonante,veces,games[players[i].game].panel);
                                            send(i,buffer,sizeof(buffer),0);

                                            if(games[players[i].game].turn==0){
                                                games[players[i].game].turn=1;
                                            }

                                            else{
                                                games[players[i].game].turn=0;
                                            }

                                            players[i].score = players[i].score - 50;

                                            bzero(buffer,sizeof(buffer));
                                            sprintf(buffer,"+Ok. %c aparece %d veces. Turno de la partida. FRASE: %s\n",consonante,veces,games[players[i].game].panel);
                                            send(games[players[i].game].players[games[players[i].game].turn],buffer,sizeof(buffer),0);
                                        }

                                        else{
                                            players[i].score = players[i].score + (veces*50);

                                            if(comprobarFinPartida(players[i].game)){
                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n",games[players[i].game].saying,players[i].name,players[i].score);
                                                send(i,buffer,sizeof(buffer),0);

                                                int otro_jugador = games[players[i].game].players[0];
                                                if(games[players[i].game].players[0]==i){
                                                    otro_jugador = games[players[i].game].players[1];
                                                }

                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n",games[players[i].game].saying,players[i].name,players[i].score);
                                                send(otro_jugador,buffer,sizeof(buffer),0);

                                                games[players[i].game].state = INACTIVA;
                                                games[players[i].game].players[0] = -1;
                                                games[players[i].game].players[1] = -1;
                                                bzero(games[players[i].game].saying,250);
                                                bzero(games[players[i].game].panel,250);
                                                players[i].state = INICIAR_PARTIDA;
                                                players[otro_jugador].state = INICIAR_PARTIDA;
                                            }

                                            else{

                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+Ok. %c aparece %d veces. FRASE: %s\n",consonante,veces,games[players[i].game].panel);
                                                send(i,buffer,sizeof(buffer),0);

                                                int otro_jugador = games[players[i].game].players[0];
                                                if(games[players[i].game].players[0]==i){
                                                    otro_jugador = games[players[i].game].players[1];
                                                }

                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+Ok. %c aparece %d veces. FRASE: %s\n",consonante,veces,games[players[i].game].panel);
                                                send(otro_jugador,buffer,sizeof(buffer),0);
                                            }
                                        }
                                    }
                                    
                                    else{
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No se encuentra en ninguna partida.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }
                                }

                                else if(strncmp(buffer,"VOCAL",5)==0){
                                    int turno = games[players[i].game].turn;
                                    if(games[players[i].game].players[turno]!=i){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No es su turno.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else if(players[i].state == JUGANDO){
                                        if(players[i].score>=50){
                                            char vocal = buffer[6];
                                            int veces = buscarConsonante(players[i].game,vocal);
                                            if(veces==0){
                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+Ok. %c aparece %d veces. FRASE: %s\n",vocal,veces,games[players[i].game].panel);
                                                send(i,buffer,sizeof(buffer),0);

                                                if(games[players[i].game].turn==0){
                                                    games[players[i].game].turn=1;
                                                }

                                                else{
                                                    games[players[i].game].turn=0;
                                                }

                                                players[i].score = players[i].score - 50;

                                                bzero(buffer,sizeof(buffer));
                                                sprintf(buffer,"+Ok. %c aparece %d veces. Turno de la partida. FRASE: %s\n",vocal,veces,games[players[i].game].panel);
                                                send(games[players[i].game].players[games[players[i].game].turn],buffer,sizeof(buffer),0);
                                            }

                                            else{

                                                players[i].score = players[i].score - 50;

                                                if(comprobarFinPartida(players[i].game)){
                                                    bzero(buffer,sizeof(buffer));
                                                    sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n",games[players[i].game].saying,players[i].name,players[i].score);
                                                    send(i,buffer,sizeof(buffer),0);

                                                    int otro_jugador = games[players[i].game].players[0];
                                                    if(games[players[i].game].players[0]==i){
                                                        otro_jugador = games[players[i].game].players[1];
                                                    }

                                                    bzero(buffer,sizeof(buffer));
                                                    sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n",games[players[i].game].saying,players[i].name,players[i].score);
                                                    send(otro_jugador,buffer,sizeof(buffer),0);

                                                    games[players[i].game].state = INACTIVA;
                                                    games[players[i].game].players[0] = -1;
                                                    games[players[i].game].players[1] = -1;
                                                    bzero(games[players[i].game].saying,250);
                                                    bzero(games[players[i].game].panel,250);
                                                    players[i].state = INICIAR_PARTIDA;
                                                    players[otro_jugador].state = INICIAR_PARTIDA;
                                                }

                                                else{
                                                    bzero(buffer,sizeof(buffer));
                                                    sprintf(buffer,"+Ok. %c aparece %d veces. FRASE: %s\n",vocal,veces,games[players[i].game].panel);
                                                    send(i,buffer,sizeof(buffer),0);

                                                    int otro_jugador = games[players[i].game].players[0];
                                                    if(games[players[i].game].players[0]==i){
                                                        otro_jugador = games[players[i].game].players[1];
                                                    }

                                                    bzero(buffer,sizeof(buffer));
                                                    sprintf(buffer,"+Ok. %c aparece %d veces. FRASE: %s\n",vocal,veces,games[players[i].game].panel);
                                                    send(otro_jugador,buffer,sizeof(buffer),0);
                                                }
                                            }
                                        }

                                        else{
                                            bzero(buffer,sizeof(buffer));
                                            strcpy(buffer,"-Err. No dispone de puntos suficientes.\n");
                                            send(i,buffer,sizeof(buffer),0);
                                        }
                                    }

                                    else{
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No se encuentra en ninguna partida\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }
                                }

                                else if(strncmp(buffer,"RESOLVER",8)==0){
                                    int turno = games[players[i].game].turn;
                                    int otro_jugador;
                                    if(games[players[i].game].players[turno]!=i){
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No es su turno.\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else if(players[i].state == JUGANDO){
                                        char * solucion = buffer + 9;
                                        solucion[strlen(solucion)-1] = '\0';
                                        if(resolver(games[players[i].game].saying,solucion)){
                                            bzero(buffer,sizeof(buffer));
                                            sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n",games[players[i].game].saying,players[i].name,players[i].score);
                                            send(i,buffer,sizeof(buffer),0);

                                            otro_jugador = games[players[i].game].players[0];
                                            if(games[players[i].game].players[0]==i){
                                                otro_jugador = games[players[i].game].players[1];
                                            }

                                            bzero(buffer,sizeof(buffer));
                                            sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n",games[players[i].game].saying,players[i].name,players[i].score);
                                            send(otro_jugador,buffer,sizeof(buffer),0);
                                            
                                        }

                                        else{
                                            bzero(buffer,sizeof(buffer));
                                            sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. No se ha acertado la frase.\n",games[players[i].game].saying);
                                            send(i,buffer,sizeof(buffer),0);

                                            otro_jugador = games[players[i].game].players[0];
                                            if(games[players[i].game].players[0]==i){
                                                otro_jugador = games[players[i].game].players[1];
                                            }

                                            bzero(buffer,sizeof(buffer));
                                            sprintf(buffer,"+Ok. Partida finalizada. FRASE: %s. No se ha acertado la frase.\n",games[players[i].game].saying);
                                            send(otro_jugador,buffer,sizeof(buffer),0);
                                        }

                                        games[players[i].game].state = INACTIVA;
                                        games[players[i].game].players[0] = -1;
                                        games[players[i].game].players[1] = -1;
                                        bzero(games[players[i].game].saying,250);
                                        bzero(games[players[i].game].panel,250);
                                        players[i].state = INICIAR_PARTIDA;
                                        players[otro_jugador].state = INICIAR_PARTIDA;
                                    }

                                    else{
                                        printf("%s\n",buffer);
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No se encuentra en ninguna partida\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }
                                }

                                else if(strncmp(buffer,"PUNTUACION",10)==0){
                                    if(players[i].state != USUARIO && players[i].state != PASSWORD){
                                        bzero(buffer,sizeof(buffer));
                                        sprintf(buffer,"Su puntuación es de %d puntos.\n",players[i].score);
                                        send(i,buffer,sizeof(buffer),0);
                                    }

                                    else{
                                        bzero(buffer,sizeof(buffer));
                                        strcpy(buffer,"-Err. No se encuentra validado\n");
                                        send(i,buffer,sizeof(buffer),0);
                                    }
                                }
                                
                                else{
                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer,"-Err. El mensaje no se ha reconocido.\n");
                                    send(i,buffer,sizeof(buffer),0);
                                }
                                /************************************************************************************************/
                            }
                            //Si el cliente introdujo ctrl+c

                            if(recibidos== 0){
                                printf("El socket %d, ha introducido ctrl+c\n", i);
                                //Eliminar ese socket
                                salirCliente(i,&readfds,&numClientes,arrayClientes);

                                if(players[i].state==JUGANDO){
                                    int j = players[i].game;
                                    games[j].state = INACTIVA;
                                    int otro_jugador = games[j].players[0];
                                    if(games[j].players[0]==i){
                                        otro_jugador = games[j].players[1];
                                    }

                                    players[otro_jugador].state = INICIAR_PARTIDA;
                                    games[j].players[0]=-1;
                                    games[j].players[1]=-1;

                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer,"+Ok. Ha salido el otro jugador. Finaliza la partida.\n");
                                    send(otro_jugador,buffer,sizeof(buffer),0);
                                }

                                bzero(buffer,sizeof(buffer));
                                strcpy(buffer,"+Ok. Desconexión procesada.\n");
                                send(i,buffer,sizeof(buffer),0);
                            }
                        }
                    }
                }
            }
		}

	close(sd);
	return 0;
}

void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]){
    char buffer[250];
    int j;
    
    close(socket);
    FD_CLR(socket,readfds);
    
    //Re-estructurar el array de clientes
    for (j = 0; j < (*numClientes) - 1; j++){
        if(arrayClientes[j] == socket){
            break;
        }
    }

    for (; j < (*numClientes) - 1; j++){
        (arrayClientes[j] = arrayClientes[j+1]);
    }
    
    (*numClientes)--;
}

void manejador(int signum){
    printf("\nSe ha recibido la señal sigint\n");
    signal(SIGINT,manejador);
}