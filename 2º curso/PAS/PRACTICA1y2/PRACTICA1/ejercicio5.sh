#!/bin/bash

function comprueba(){ #recibe 2 parametros y comprueba si el resumen pasado y el resumen del valor es el mismo. 
	y=$(echo $2 | sha256sum | cut -b -64)
	if [ $y == $1 ]
	then
		echo -e "Se ha encontrado la contraseña: $2"
		exit 0
	fi
}

while read linea
do
	pass=$(echo "$linea"| cut -b -64)

	for (( i = 1; i <= 5; i++ )); 
	do
		let combinaciones=16**$i

		echo "Probando $combinaciones combinaciones de longitud $i"

		for (( j = 0; j < $combinaciones; j++ )); 
		do
			x=$(echo "ibase=10;obase=16;$j" | bc)
			comprueba $pass $x
		done
	done
	
done < hash.txt

