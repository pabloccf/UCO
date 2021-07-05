#!/bin/bash

#El sistema de ficheros none está montado en /dev y tiene un tamaño de 5,9G, de los cuales se están
#usando 260K, que representan un 1 % del total. Quedan libres 5,9G.

#df | sed -r -n -e 's/(.+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)//p'

fichero=$(mktemp)

df > $fichero
cont=0
while read linea
do
	if [ $cont -ne 0 ]
	then
		sistema=$(echo "$linea" | sed -r -n -e 's/([^ ]+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)/\1/p')
		montaje=$(echo "$linea" | sed -r -n -e 's/(.+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)/\6/p')
		tamano=$(echo "$linea" | sed -r -n -e 's/(.+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)/\2/p')
		let tamano=$tamano/1024/1024
		usado=$(echo "$linea" | sed -r -n -e 's/(.+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)/\3/p')
		porcentaje=$(echo "$linea" | sed -r -n -e 's/(.+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)/\5/p')
		libre=$(echo "$linea" | sed -r -n -e 's/(.+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +(.+)/\4/p')
		let libre=$libre/1024/1024

		echo "El sistema de ficheros $sistema está montado en $montaje y tiene un tamaño de $tamano G, de los cuales se están usando $usado K, que representan un $porcentaje del total. Quedan libres $libre G."	
	else
		cont=1	
	fi
done < $fichero


rm $fichero