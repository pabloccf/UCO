#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>


void help(){
    printf("Uso del programa: ejercicio1 [opciones]\n");
    printf("Opciones:\n");
    printf("-h, --help\n");
    printf("Imprimir esta ayuda\n");
    printf("-u, --user (<nombre>|<uid>) Información sobre el usuario\n");
    printf("-a, --active\n");
    printf("Información sobre el usuario activo actual\n");
    printf("-m, --maingroup\n");
    printf("Además de info de usuario, imprimir la info de su\n");
    printf("grupo principal\n");
    printf("-g, --group (<nombre>|<gid>) Información sobre el grupo\n");
    printf("-s, --allgroups\n");
    printf("Muestra info de todos los grupos del sistema\n");
}

//Campos de la estructura passwd
void imprimirDatosUsuario(struct passwd * pw){
	printf("Nombre: %s\n", pw->pw_gecos);
    printf("Login: %s\n", pw->pw_name);
    printf("Password: %s\n", pw->pw_passwd);
    printf("UID: %d\n", pw->pw_uid);
    printf("Home: %s\n", pw->pw_dir);
    printf("Shell: %s\n", pw->pw_shell);
    printf("Número de grupo principal: %d\n", pw->pw_gid);
}

//Campos de la estructura group
void imprimirDatosGrupo(struct group * gr){
	printf("Nombre del grupo: %s\n", gr->gr_name);
   	printf("GID: %d\n", gr->gr_gid);
    printf("Password group: %s\n", gr->gr_passwd);
    printf("Member list: %s\n", *gr->gr_mem);
}

int main(int argc, char ** argv){
	//DECLARO LAS BANDERAS, POR DEFECTO DESACTIVADAS
	bool hflag = false;  //Bandera para --help
    char * uvalue = NULL;  //Bandera para --user y es char porque tienes que introducir un nombre de usuario detras de esta opcion
    bool mflag = false;  //Bandera para --maingroup
    bool aflag = false;  //Bandera para --active
    char * gvalue = NULL;  //Bandera para --group y es char porque tienes que introducir un nombre de grupo o un argumentos detras de esta opcion 
    bool sflag = false;  //Bandera para --allgroups

    //ESTRUCTURAS PARA CARGAR INFORMACION
    struct passwd * pw; //donde almaceno informacion de un usuario
    struct group * gr; //aqui de un grupo

    //ESTRUCTURA DONDE ALMACENAMOS LA RELACION DE NOMBRES CORTOS Y LARGOS
    static struct option long_options[] = {
        //{<nombre largo>, <recibe/no recibe argumento>, NULL, <nombre corto>}
        {"help", no_argument, NULL, 'h'},
        {"user", required_argument, NULL, 'u'},
        {"maingroup", no_argument, NULL, 'm'},
        {"active", no_argument, NULL, 'a'},
        {"group", required_argument, NULL, 'g'},
        {"allgroups", no_argument, NULL, 's'},
        /* Necesario para indicar el final de las opciones */
        {0, 0, 0, 0}
    };

	//RECONOZCO LAS OPCIONES RECIBIDAS Y ACTIVO SUS RESPECTIVAS BANDERAS
    int c;
	while ((c= getopt_long(argc, argv, "hu:mag:s", long_options, NULL)) != -1){  //Los dos puntos se ponen detras de una opcion que tiene que llevar un argumento obligatoriamente
        switch (c){
            case 'h':
                hflag = true; 
            break;

            case 'u':
                uvalue = optarg;  //En optarg queda guardado el parametro obligatorio que recibe u
            break;

            case 'm':
                mflag = true;
            break;

            case 'a':
                aflag = true; 
            break;

            case 'g':
                gvalue = optarg;  //En optarg queda guardado el parametro obligatorio que recibe g
            break;

            case 's':
                sflag = true;
            break;

            case '?':              
                if (optopt == 'u'){
                    fprintf(stderr,
                        "La opción %c requiere un argumento. Valor de opterr = "
                        "%d\n",
                        optopt, opterr);
                }

                if (optopt == 'g'){
                    fprintf(stderr,
                        "La opción %c requiere un argumento. Valor de opterr = "
                        "%d\n",
                        optopt, opterr);
                }

                else if (isprint(optopt)){
                    fprintf(stderr,
                        "Opción desconocida \"-%c\". Valor de opterr = %d\n",
                        optopt, opterr);
                }

                else{
                    fprintf(stderr, "Caracter `\\x%x'. Valor de opterr = %d\n",
                        optopt, opterr);
                }

                return 1; 
            default:
                abort();
        }
    }

    /*
    COMBINACIONES POSIBLES:
        --help, junto con cualquiera (se ignoran las demás)
        vacío
        --user <usuario>
        --user <usuario> --maingroup
        --active
        --active --maingroup
        --group <grupo>
        --allgroups
    */

    //CONTROL DE ERRORES
    if(uvalue!=NULL && (aflag==true || gvalue!=NULL || sflag==true)){
        printf("La opcion --user solo se puede acompañar de --maingroup.\n");
        help();
        return 1;
    }

    if(aflag==true && (uvalue!=NULL || gvalue!=NULL || sflag==true)){
        printf("La opcion --user solo se puede acompañar de --maingroup.\n");
        help();
        return 1;
    }

    if(gvalue!=NULL && (uvalue!=NULL || mflag==true || aflag==true || sflag==true)){
        printf("La opcion --group no se puede acompañar de ninguna otra opcion.\n");
        help();
        return 1;
    }

    if(sflag==true && (uvalue!=NULL || mflag==true || gvalue!=NULL || aflag==true)){
        printf("La opcion --allgroups no se puede acompañar de ninguna otra opcion.\n");
        help();
        return 1;
    }

    if(mflag==true && uvalue==NULL && aflag==false){
    	printf("La opcion --maingroup debe ir acompañada de --user o --active.\n");
        help();
        return 1;
    }

    //AÑADIR FUNCIONALIDAD SEGÚN LAS BANDERAS ACTIVAS
    if(hflag == true){
        help();
        return 0;
    }

    //Se ha activado la opcion --user
    if(uvalue!=NULL){
        /*
        Para cargar el struct passwd con los datos de un usuario, necesito o bien el nombre del usuario, 
        o bien el UID del usuario. 
        */

        //Lo primero es ver si uvalue contiene un nombre de usuario o un uid y cargar la informacion de dicho usuario
        char * endptr = NULL;
        long uid = strtol(uvalue, &endptr, 10);  //Convierte una string a un long int
        if (((*uvalue) != '\0') && ((*endptr) == '\0')){
            //strtol tiene éxito, la cadena contiene un número
            if((pw = getpwuid(uid)) == NULL){
                printf("El UID de usuario no existe en el sistema.\n");
                return 1;
            }

        } 
        else{
            //strtol ha encontrado un error, la cadena NO contiene un número
            if((pw = getpwnam(uvalue)) == NULL){
                printf("El nombre de usuario no existe en el sistema.\n");
                return 1;
            }
        }

        //Imprimo la informacion del usuario
        imprimirDatosUsuario(pw);

        //Miro si la bandera mflag esta activa
        if(mflag == true){
            gr = getgrgid(pw->pw_gid);
            imprimirDatosGrupo(gr);
        }


    }

    //Se ha activado la opcion --active
    if(aflag==true){
        //char * usuario_activo = getlogin();
        char * usuario_activo = getenv("USER");
        pw = getpwnam(usuario_activo);

        imprimirDatosUsuario(pw);

        if(mflag==true){
        	gr = getgrgid(pw->pw_gid);
            imprimirDatosGrupo(gr);
        }
    }

    //Se ha activado la opcion --group
    if(gvalue!=NULL){
		char * endptr = NULL;
        long gid = strtol(gvalue, &endptr, 10);  //Convierte una string a un long int
        if (((*gvalue) != '\0') && ((*endptr) == '\0')){
            //strtol tiene éxito, la cadena contiene un número
            if((gr = getgrgid(gid)) == NULL){
                printf("El GID de grupo no existe en el sistema.\n");
                return 1;
            }

        } 
        else{
            //strtol ha encontrado un error, la cadena NO contiene un número
            if((gr = getgrnam(gvalue)) == NULL){
                printf("El nombre de grupo no existe en el sistema.\n");
                return 1;
            }
        }

        imprimirDatosGrupo(gr);
    }

    //Se ha activado la opcion --allgroups
    if(sflag==true){
    	FILE * fich = NULL;
    	fich = fopen("/etc/group","r");
    	if(fich==NULL){
    		printf("Error al abrir el fichero /etc/group\n");
    		return 1;
    	}

    	char lineaLeida[500];
    	char * nombreGrupo;

    	while(fgets(lineaLeida,500,fich)){
    		nombreGrupo = strtok(lineaLeida,":");
    		gr = getgrnam(nombreGrupo);
    		imprimirDatosGrupo(gr);
    	}

    	fclose(fich);
    }

    //CASO VACIO
    if(uvalue==NULL && aflag==false && gvalue==NULL && sflag==false){
    	char * usuario_activo = getenv("USER");
        pw = getpwnam(usuario_activo);
        imprimirDatosUsuario(pw);

    	gr = getgrgid(pw->pw_gid);
        imprimirDatosGrupo(gr);
    }


	return 0;
}