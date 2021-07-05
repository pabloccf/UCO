#!/bin/bash

#root:x:0:0:root:/root:/bin/bash
#nombre usuario : password : id usuario : id grupo : gecos : dir home : interprete

#Primer punto
echo ""
echo "1) Mostrar los usuarios que tengan un intérprete de comandos válido asignado"
echo ""
echo ""
while read linea
do

	interprete=$(echo "$linea" | sed -r -n -e 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\7/p')
	if [ -n "$interprete" ]
	then
		echo "$linea"
	fi
done < /etc/passwd

#Segundo punto
echo ""
echo "2) Mostrar los usuarios que tengan un home válido asignado"
echo ""
echo ""
while read linea
do

	home=$(echo "$linea" | sed -r -n -e 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\6/p')
	if [ -n "$home" ]
	then
		echo "$linea"
	fi
done < /etc/passwd


#Tercer punto
echo ""
echo "3) Mostrar los usuarios y el nombre de su grupo en dos columnas"
echo ""
echo ""
echo -e "Usuario\t\t\t\tGrupo"
echo "=============================================================="
while read linea
do

	usuario=$(echo "$linea" | sed -r -n -e 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\1/p')
	idgrupo=$(echo "$linea" | sed -r -n -e 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\4/p')

	if [ -z "$idgrupo" ]
	then
		grupo="-"
	else
		#busco el nombre de ese idgrupo en el fichero /etc/group
		#nombre grupo : password : id grupo : miembros grupo
		grupo=$(cat /etc/group | sed -r -n -e "s/(.*):(.*):$idgrupo:(.*)/\1/p")
	fi

	echo -e "$usuario\t\t\t\t\t$grupo"
	
done < /etc/passwd