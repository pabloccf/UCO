#include <ctype.h>

#include "estructuras.h"

void iniciarArrays(){
	for (int i = 0; i < 50; i++){
		strcpy(players[i].name,"");
		players[i].state = USUARIO;
		players[i].score = 0;
		players[i].game = -1;
	}

	for (int i = 0; i < 10; i++){
		games[i].state = INACTIVA;
		games[i].players[0] = -1;
		games[i].players[1] = -1;
		games[i].turn = 0;
	}
}

int comprobarUsuario(char* username){
	FILE * f = fopen("login.txt","r");
	if(f!=NULL){
		char user[350];
		char password[350];
		while(fscanf(f,"%s %s", user, password)==2){
			if(!strcmp(user, username)){
				fclose(f);
				return 1;
			}
		}

		fclose(f);
		return 0;
	}
	
	return 0;
}

int comprobarContrasena(char* username,char* password){
	FILE * f = fopen("login.txt","r");
	if(f!=NULL){
		char user[350];
		char password[350];
		while(fscanf(f,"%s %s",user, password)==2){
			if(!strcmp(user, username) && !strcmp(password, password)){
				fclose(f);
				return 1;
			}
		}

		fclose(f);
		return 0;
	}
	
	return 0;
}

int nuevoUsuario(char* username,char* password){
	FILE * f = fopen("login.txt","a");
	if(f!=NULL){
		fprintf(f,"%s %s\n",username, password);
		fclose(f);
		return 1;
	}

	return 0;
}

void obtenerRefran(char * refran){
	FILE * f = fopen("refranesPopulares.txt","r");
	if(f!=NULL){
		char linea[250];
		int i=0;
		srand(time(NULL));
		int seleccionado = rand()%10;
		while (fgets(linea, 250, f)){
			linea[strlen(linea)-1]='\0';
			if(seleccionado==i){
				bzero(refran,250);
				strcpy(refran,linea);
				fclose(f);
				return;
			}

			i++;
		}
		
		fclose(f);
	}
}

int buscarPartida(int socket){
	for (int i = 0; i < 10; i++){
		if(games[i].state==INACTIVA && games[i].players[0]!=-1){
			games[i].players[1]=socket;
			games[i].turn=0;
			games[i].state = ACTIVA;
			players[socket].game = i;
			return i;
		}
	}

	for (int i = 0; i < 10; i++){
		if(games[i].state==INACTIVA && games[i].players[0]==-1){
			games[i].players[0]=socket;
			players[socket].game = i;
			return i;
		}
	}

	return -1;
}

int buscarConsonante(int id_partida, char c){
	int veces = 0;

	for (int i = 0; i < strlen(games[id_partida].saying); i++){
		if(tolower(games[id_partida].saying[i]) == tolower(c)){
			games[id_partida].panel[i] = games[id_partida].saying[i];
			veces++;
		}
	}

	return veces;
}

int comprobarFinPartida(int id_partida){
	if(strcmp(games[id_partida].saying,games[id_partida].panel)==0){
		return 1;
	}
	else{
		return 0;
	}
}

int resolver(char* refran, char* solution){
	for (int i = 0; i < strlen(refran); i++){
		if(tolower(refran[i])!=tolower(solution[i])){
			return 0;
		}
	}

	return 1;
}
