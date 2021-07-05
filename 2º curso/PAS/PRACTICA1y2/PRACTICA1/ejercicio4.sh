#!/bin/bash

menu()
{
	echo "=== Personalizaci´on del prompt ==="
	echo "Selecciona una opci´on para añadirle al prompt:"
	echo "1. Nombre de usuario"
	echo "2. Nombre de host"
	echo "3. Ruta completa"
	echo "4. Última parte de la ruta"
	echo "5. Hora"
	echo "6. Fecha"
	echo "7. Cadena literal"
	echo "8. Añadir color y estilo"
	echo "9. Cancelar"
	echo "0. Confirmar"
	read opcion
}


datos=""
menu
while [ $opcion -ne 9 ]
do
	case $opcion in

		1)
			datos=$datos"\u"
			;;
		
		2)
			datos=$datos"@\h"
			;;

		3)
			datos=$datos"\w"
			;;

		4)
			datos=$datos"\W"
			;;

		5)
			datos=$datos"\A"
			;;

		6)
			datos=$datos"\d"
			;;

		7)
			read cadena
			datos=$datos" $cadena"
			;;

		8)
			echo "- Tipo de fuente -"
			echo "1. Normal"
			echo "2. Negrita"
			echo "3. Subrayado"
			read op1

			echo "- Color de fuente -"
			echo "1. Negro"
			echo "2. Rojo"
			echo "3. Verde"
			echo "4. Amarillo"
			echo "5. Azul"
			echo "6. Blanco"
			read op2

			
			echo "- Color de fondo -"
			echo "1. Negro"
			echo "2. Rojo"
			echo "3. Verde"
			echo "4. Amarillo"
			echo "5. Azul"
			echo "6. Blanco"
			read op3

			#ponemos \e[ para iniciar la edicion del formato
			datos=$datos"\e["

			#primero el tipo de fuente
			if [ $op1 -eq 1 ]
			then
				datos=$datos"0"
			elif [ $op1 -eq 2 ]
			then
				datos=$datos"1"
			else
				datos=$datos"4"
			fi

			#punto y coma
			datos=$datos";"

			#color de texto
			if [ $op2 -eq 1 ]
			then
				atos="$datos 30"
			elif [ $op2 -eq 2 ]
			then
				datos=$datos"31"
			elif [ $op2 -eq 3 ]
			then
				datos=$datos"32"
			elif [ $op2 -eq 4 ]
			then
				datos=$datos"33"
			elif [ $op2 -eq 5 ]
			then
				datos=$datos"34"
			else
				datos=$datos"37"
			fi

			#punto y coma
			datos=$datos";"

			#color de fondo
			if [ $op3 -eq 1 ]
			then
				datos=$datos"40m"
			elif [ $op3 -eq 2 ]
			then
				datos=$datos"41m"
			elif [ $op3 -eq 3 ]
			then
				datos=$datos"42m"
			elif [ $op3 -eq 4 ]
			then
				datos=$datos"43m"
			elif [ $op3 -eq 5 ]
			then
				datos=$datos"44m"
			else
				datos=$datos"47m"
			fi

			;;

		0)
			PROMPT_COMMAND="PS1='$datos';unset PROMPT_COMMAND" bash
			exit 1
			;;

		*)
			echo "Opción incorrecta."
			;;
	esac
	echo "PROMPT ACTUAL: $datos"
	menu
done
	

