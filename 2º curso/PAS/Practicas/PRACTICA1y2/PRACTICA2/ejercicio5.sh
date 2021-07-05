#!/bin/bash

#USUARIO  TTY      DE               LOGIN@   IDLE   JCPU   PCPU WHAT
#angel    :0       :0               09:00   ?xdm?   2:55   0.02s /usr/lib/gdm3/gdm-x-session --run-script env GNOME_SHELL_SESSION_MODE=ubuntu /usr/bin

fichero=$(mktemp)

w > $fichero

cont=0

while read linea
do
	if [ $cont -eq 2 ]
	then
		usuario=$(echo "$linea" | sed -r -n -e "s/^([a-z]+) +.+ +.+ +([0-9][0-9]:[0-9][0-9]) +.+ +[0-9]+:[0-9][0-9] +.+ +.+$/\1/p")
		hora=$(echo "$linea" | sed -r -n -e "s/^([a-z]+) +.+ +.+ +([0-9][0-9]:[0-9][0-9]) +.+ +[0-9]+:[0-9][0-9] +.+ +.+$/\2/p")
		ausente=$(echo "$linea" | sed -r -n -e "s/^([a-z]+) +.+ +.+ +([0-9][0-9]:[0-9][0-9]) +.+ +([0-9]+:[0-9][0-9]) +.+ +.+$/\3/p")

		HH=$(echo "$ausente" | sed -r -n -e 's/([0-9]*):?([0-9]+):([0-9]+)/\1/p')
		mm=$(echo "$ausente" | sed -r -n -e 's/([0-9]*):?([0-9]+):([0-9]+)/\2/p')
		ii=$(echo "$ausente" | sed -r -n -e 's/([0-9]*):?([0-9]+):([0-9]+)/\3/p')

		if [ -z "$HH" ]
		then
			HH="00"
		fi

		echo "El usuario $usuario lleva conectado desde las $hora y lleva ausente $HH:$mm:$ii"
	else
		let cont=$cont+1
	fi

	

done < $fichero