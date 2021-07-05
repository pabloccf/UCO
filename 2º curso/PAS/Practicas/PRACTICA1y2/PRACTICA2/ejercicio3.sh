#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Debe introducir el nombre de un fichero obligatoriamente."
else
	fichero=$1

	echo -e "Contraseña \t Minúsculas \t Mayúsculas \t Números \t Sı́mbolos \t Puntos"
	echo "======================================================================================"

	while read linea
	do
		linea=$(echo "$linea" | tr -d " ")
		longitud=$(echo -n "$linea" | wc -c)
		minusculas=$(echo -n $linea | tr -c -d "[:lower:]" | wc -c)
		mayusculas=$(echo -n $linea | tr -c -d "[:upper:]" | wc -c)
		numeros=$(echo -n $linea | tr -c -d "[:digit:]" | wc -c)
		simbolos=$(echo -n "$linea" | tr -d "[:alnum:]" | wc -c)

		puntos=0
		if [ $longitud -ge 5 ]
		then
			if [ $longitud -ge 8 ]
			then
				puntos=5
			fi

			if [ $longitud -ge 15 ]
			then
				let puntos=$puntos+20
			fi

			if [ $minusculas -ge 1 ]
			then
				let puntos=$puntos+10
			fi

			if [ $mayusculas -ge 1 ]
			then
				let puntos=$puntos+10
			fi

			if [ $numeros -ge 1 ]
			then
				let puntos=$puntos+5
			fi

			if [ $simbolos -ge 1 ]
			then
				let puntos=$puntos+15
			fi

			puntos=$(($puntos+$numeros+(2*($mayusculas+$minusculas))+(3*$simbolos)))
		fi

		

		echo -e "$linea \t\t\t $minusculas \t $mayusculas \t $numeros \t $simbolos \t $puntos"
	done < $fichero | sort -k 6 -n -r
fi