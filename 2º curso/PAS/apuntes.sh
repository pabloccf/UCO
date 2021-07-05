#!/bin/bash

COMANDOS

- chmod : para modificar permisos
		
		chmod u+x nombrefichero
		chmod 777 nombrefichero

- echo : equivalente a cout

		echo -n : quita el salto de linea
		echo -e : tiene expresiones como /n

- $# : numero de argumentos por linea de argumentos

- read : equivalente a cin

		read -p : echo + read
		read -n numero -p : establece numero de caracteres a escribir
		read -t numero :  acepta la entrada durante un tiempo máximo de T segundos.

- let : permite a una variable ser operada como entero

- rm : para borrar un fichero

		rm -r : borrar directorios y su contenido recursivamente

- basename : elimina la ruta de direccion de un fichero. Se queda con su nombre. Ej: nombre=$(basename $x)

- dirname : ruta completa de un fichero

- wc : contar

		wc -m : contar caracteres
		wc -l : contar lineas

- stat : proporciona datos del fichero

		stat -c : te dice un campo en concreto
		stat -c %Y : fecha de creacion de un fichero/directorio

- mkdir : crear directorios

- cp : copiar algo a un directorios

- cut : cortar una linea

		cut -d ' ' -f4 : cortar linea en columnas hasta que haya espacios, me quedo con la columna 4
		cut -f : 

- sort : para ordenar

		echo "$lineas_fich,$nombre_sin_ruta,$tam,$inode,$permisos" | sort -t',' -k1 -n -r : ordeno separando por , por la columna 1 de mayor a menor

- who : usuarios logueados

- cat : muestra el fichero por pantalla

- grep -E "" o '' dentro expresion regular

		grep -E -i : da igual mayuscula o minuscula
		grep -E -o : corta el patron
		grep -E -v : se queda con lo que no cumple el patron

- sed -r -n -e 's///p'

- awk '{ print $4}' : imprime  columna

- tr : reemplazar caracteres

- mv : mover algo a otro lugar

- date +%s : hora actual


- #Calculo el número de líneas de cada fichero
		lineas_fich=$(cat $x | wc -l)




