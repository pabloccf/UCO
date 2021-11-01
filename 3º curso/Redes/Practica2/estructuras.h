//Estados del jugador
#define USUARIO 0
#define PASSWORD 1
#define INICIAR_PARTIDA 2
#define JUGANDO 3

//Estados de la partida
#define ACTIVA 0
#define INACTIVA -1

struct player{
	char name[256];
	int state;		//Estado en el que se encuentra el jugador (USUARIO, PASSWORD...)
	int score; //Puntuacion del jugador
	int game;  //En que partida estas jugando
};

struct game{
	int state;			//Estado de la partida (ACTIVA O INACTIVA)
	int players[2];  //Es un entero porque va a guardar el estado de los jugadores de la partida.
	int turn;			//Variable que nos servirá para intercambiar los turnos de los jugadores
	char saying[250];	//El refran que se seleccione
	char panel[250];  //El panel de los guiones
};

struct player players[50];
struct game games[10];