#!/bin/bash

if [ $# -ne 2 ]
then
	echo "El script debe recibir dos argumentos obligatoriamente."
else
	if [ -d $1 ]
	then
		#EJERCICIO
		directorio=$1
		grupos=$2

		numero_ficheros=0
		for x in $(ls $1)
		do
			let numero_ficheros=$numero_ficheros+1
		done

		if [ $grupos -gt $numero_ficheros ]
		then
			echo "ERROR: No se pueden hacer $grupos grupos con $numero_ficheros ficheros."
		else
			let tam_grupo=$numero_ficheros/$grupos
			echo "$numero_ficheros files, $grupos groups -> size of groups $tam_grupo"

			#Antes de crear los directorios, los borramos si existen
			if [ -d groups ]
			then
				rm -r groups/
			fi

			#Creo los directorios

			#creo el directorio groups/
			mkdir groups/

			#Creo tantos directorios como indique por argumentos en la carpeta groups
			for (( i=1; $i<=$grupos; i=$i+1 ))
			do
				mkdir groups/group$i
			done

			#Recorrer el directorio e ir copiando los ficheros a las carpetas groups que he creado
			#para copiar usamos el comando cp
			#cp lo-que-copio a-donde-copio

			cont=1
			num_grupo=1
			for x in $(ls $1)
			do
				if [ -f $1/$x ]
				then
					if [ $cont -le $tam_grupo ]  #si el contador es menor o igual que el tamaño del grupo...
					then
						cp $1/$x groups/group$num_grupo
					else
						let num_grupo=$num_grupo+1
						cont=1
						cp $1/$x groups/group$num_grupo
					fi

					let cont=$cont+1
				fi
			done
		fi

	else
		echo "El primer argumento debe ser un directorio."
	fi
fi
