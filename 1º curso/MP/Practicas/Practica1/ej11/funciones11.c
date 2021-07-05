#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones11.h"
int es_prefijo(char* cadena,char* prefijo){
	char* pref=strstr(cadena,prefijo);
	if(pref!=NULL){
		if(pref==cadena){
			return 1;
		}
	}
	return 0;
}
int es_sufijo(char* cadena,char* sufijo){
	char* suf=strstr(cadena,sufijo);
	if(suf!=NULL){
		int cad_len=strlen(cadena);
		int suf_len=strlen(sufijo);
		if(suf==cadena+(cad_len-suf_len)){
			return 1;
		}
	}
	return 0;
}