#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones7.h"
void leervector(int nv,int v[]){
	for(int i=0;i<nv;i++){
		scanf("%d",&v[i]);
	}
}
void imprimirvector(int nv,int v[]){
	for(int i=0;i<nv;i++){
		printf("Elemento numero %d: %d\n",i,v[i]);
	}
}
void estadisticasVector(int nv,int v[],float* media,float* varianza,float* desvtip){
	float sum=0;
	for(int i=0;i<nv;i++){
		sum+=v[i];
	}
	*media=sum/nv;

	sum=0;
	for(int i=0;i<nv;i++){
		sum+=v[i]*v[i];

	}
	
	*varianza=sum/nv;
	*varianza-=(*media)*(*media);
	*desvtip=sqrt(*varianza);
}