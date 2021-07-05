#!/bin/bash

if [ $# -ne 1 ]
then
	echo "ERROR debe introducir un argumento obligatoriamente, este debe ser un directorio."
else
	if [ -d $1 ]
	then
		#EJERCICIO
		#Para recorrer un directorio recursivamente utilizamos dir
		#Primera parte
		for x in $(find $1)
		do
			#fichero_con_ruta=$x
			fichero_sin_ruta=$(basename $x)
			caracteres=$(echo $fichero_sin_ruta | wc -m)
			if [ $caracteres -gt 1 ]  #si los caracteres es mayor que 1...
			then
				echo "$fichero_sin_ruta <- $caracteres caracteres"
			else
				echo "$fichero_sin_ruta <- $caracteres caracter"
			fi
		done

		echo ""
		echo "============================================================================="
		echo ""

		#segunda parte
		for x in $(find $1)
		do
			fichero_sin_ruta=$(basename $x)
			caracteres=$(echo $fichero_sin_ruta | wc -m)
			let modulo=$caracteres%2
			if [ $modulo -eq 1 ]
			then
				# 1. Nombre del fichero (sin la ruta).
				fichero_sin_ruta=$(basename $x)
				# 2. Ruta absoluta en la que se encuentra.
				ruta=$(dirname $x)
				# 3. Número de i-nodo.
				inodo=$(stat -c %i $x)
				# 4. Tamaño del fichero en bytes y en kilobytes.
				tam_bytes=$(stat -c %s $x)
				let tam_kbytes=$tam_bytes/1024
				# 5. Permisos en formato octal.
				permisos_octal=$(stat -c %a $x)
				# 6. Usuario y grupo al que pertenece.
				usuario_propietario=$(stat -c %U $x)
				grupo_propietario=$(stat -c %G $x)

				echo "$fichero_sin_ruta, $ruta, i-nodo $inodo, $tam_bytes bytes ($tam_kbytes kB) , permisos: $permisos_octal ($usuario_propietario : $grupo_propietario)"
			fi
		done	
	else
		echo "ERROR el argumento debe ser un directorio."
	fi
fi