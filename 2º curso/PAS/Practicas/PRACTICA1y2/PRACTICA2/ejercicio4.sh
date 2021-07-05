#!/bin/bash

# MemTotal:        4001764 kB
# MemFree:          950048 kB
# MemAvailable:    2163720 kB
# Cached:          1217420 kB
# SwapTotal:       1942896 kB
# SwapFree:        1942896 kB

cat /proc/meminfo | sed -r -n -e 's/MemTotal: +([0-9]+ kB)/Memoria total: \1/p'
cat /proc/meminfo | sed -r -n -e 's/MemFree: +([0-9]+ kB)/Memoria libre: \1/p'
cat /proc/meminfo | sed -r -n -e 's/MemAvailable: +([0-9]+ kB)/Memoria disponible: \1/p'
cat /proc/meminfo | sed -r -n -e 's/Cached: +([0-9]+ kB)/Memoria usada como caché de disco: \1/p'
cat /proc/meminfo | sed -r -n -e 's/SwapTotal: +([0-9]+ kB)/Tamaño de la memoria swap: \1/p'
cat /proc/meminfo | sed -r -n -e 's/SwapFree: +([0-9]+ kB)/Memoria swap libre: \1/p'

echo ""

if [ $# -eq 1 ]
then
	top=$1
else
	top=10
fi

#root           1  0.0  0.2 167720 11708 ?        Ss   00:56   0:03 /sbin/init splash

echo "Top-$top procesos en uso de memoria."
echo "============================================================="
echo -e "Usuario \t %Uso \t Proceso"
echo "============================================================="

fichero=$(mktemp)
fichero2=$(mktemp)

ps aux > $fichero

while read linea
do
	echo "$linea" | sed -r -n -e 's/^([a-Z]+) +[0-9]+ +[0-9]+\.[0-9]+.* +([0-9]+\.[0-9]+) +.+ +.+ +.+ +.+ +.+ +.+ +.+ +(.+)$/\1;\2;\3/p' >> $fichero2
done < $fichero

sort -t";" -k2 -n -r $fichero2 > $fichero

cont=0
while read linea
do
	if [ $cont -lt $top ]
	then
		usuario=$(echo $linea | cut -d";" -f1)
		porcentaje=$(echo $linea | cut -d";" -f2)
		proceso=$(echo $linea | cut -d";" -f3)
		echo -e "$usuario \t\t $porcentaje \t $proceso"
	else
		break
	fi
	let cont=$cont+1
done < $fichero

rm $fichero $fichero2

