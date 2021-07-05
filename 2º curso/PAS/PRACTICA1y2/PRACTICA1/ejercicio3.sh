#!/bin/bash

#./ejercicio3.sh exampleFiles/ backup/ 5

#control de errores de linea de argumentos
if [ $# -ne 3 ]
then
	echo "ERROR en linea de argumentos..."
else
	#compruebo que el primer argumento es un directorio
	if [ ! -d $1 ]
	then
		echo "ERROR, el primer argumento debe ser un directorio."
	else
		#si el segundo directorio no existe hay que crearlo
		if [ ! -d $2 ]
		then
			mkdir $2
		fi

		#Hay que ver cuantas carpetas hay en $2 (backup)
		for x in $(ls $2)
		do
			let num_carpeta=$x
		done
		#echo "La carpeta con el numero mas grande en $2 es $carpeta"

		#si el numero de carpetas ya es el maximo, es decir $3, hay que borrar la primera
		if [ $num_carpeta -eq $3 ]
		then
			rm -r $2/1   #Elimino la carpeta 1 que esta dentro del directorio $2 (backup)
			echo "Copia 1 eliminada"
			#renombrar el resto de las carpetas
			for x in $(ls $2)
			do
				#para renombrar usamos el comando mv (move)
				#mv origen destino
				#cuando movemos algo de un sitio a otro podemos cambiarle el nombre
				let x_nueva=$x-1
				mv $2/$x $2/$x_nueva
			done
			mkdir $2/$num_carpeta
		else
			let num_carpeta=$num_carpeta+1
			mkdir $2/$num_carpeta
		fi

		#ya esta todo listo para hacer la copia de $1 a $2/$num_carpeta
		for x in $(ls $1)
		do
			cp $1/$x $2/$num_carpeta
		done
		echo "Nueva copia creada en $2/$num_carpeta"

	fi
fi


#COMANDOS

#- chmod : para modificar permisos
		
#		chmod u+x nombrefichero
#		chmod 777 nombrefichero

#- echo : equivalente a cout

#		echo -n : quita el salto de linea
#		echo -e : tiene expresiones como /n

#- $# : numero de argumentos por linea de argumentos

#- read : equivalente a cin

#		read -p : echo + read
#		read -n numero -p : establece numero de caracteres a escribir
#		read -t numero :  acepta la entrada durante un tiempo máximo de T segundos.

#- let : permite a una variable ser operada como entero

#- rm : para borrar un fichero

#		rm -r : borrar directorios y su contenido recursivamente

#- basename : elimina la ruta de direccion de un fichero. Se queda con su nombre. Ej: nombre=$(basename $x)

#- dirname : ruta completa de un fichero

#- wc : contar

#		wc -m : contar caracteres
#		wc -l : contar lineas

#- stat : proporciona datos del fichero

#		stat -c : te dice un campo en concreto
#		stat -c %Y : fecha de creacion de un fichero/directorio
#		stat -c %U : nombre de usuario del propietario
#		stat -c %i : numero inodo

#- mkdir : crear directorios

#- cp : copiar algo a un directorios

#- cut : cortar una linea

#		cut -d ' ' -f4 : cortar linea en columnas hasta que haya espacios, me quedo con la columna 4
#		cut -f : 

#- sort : para ordenar

#		echo "$lineas_fich,$nombre_sin_ruta,$tam,$inode,$permisos" | sort -t',' -k1 -n -r : ordeno separando por , por la columna 1 de mayor a menor

#- who : usuarios logueados

#- cat : muestra el fichero por pantalla

#- grep -E "" o '' dentro expresion regular

#		grep -E -i : da igual mayuscula o minuscula
#		grep -E -o : corta el patron
#		grep -E -v : se queda con lo que no cumple el patron

#- sed -r -n -e 's///p'

#- awk '{ print $4}' : imprime  columna

#- tr : reemplazar caracteres

#- mv : mover algo a otro lugar

#- date +%s : hora actual


#- Calculo el número de líneas de cada fichero
#		lineas_fich=$(cat $x | wc -l)