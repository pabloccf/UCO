#!/bin/bash

echo "1) Mostrar los datos de las pelı́culas en el formato indicado"
echo ""

while read linea
do
	#Linea del principio
	if [ -n "$(echo "$linea" | grep -E '<article>')" ]
	then
		linea=$(echo "$linea" | grep -E '<article>' | sed -r -n -e 's/(.+)/=========================================/p')
	fi


	#Título
	if [ -n "$(echo "$linea" | grep -E -i '<h2>')" ]
	then
		titulo=$(echo "$linea" | grep -E -i '<h2>' | sed -r -n -e 's/.+>(.+) \([0-9]+\)<.+/Título: \1/p')
	fi


	#Año
	if [ -n "$(echo "$linea" | grep -E -i "<h2>")" ]
	then
		anio=$(echo "$linea" | grep -E -i "<h2>" | sed -r -n -e 's/.+>.+ \(([0-9]+)\)<.+/Año: \1/p')
	fi


	#Valoración
	if [ -n "$(echo "$linea" | grep -E "id=\"rating\"")" ]
	then
		nota=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\1/p')
		if [ -n "$nota" ]
		then
			valoraciones=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\3/p')
		fi
	fi


	#duración
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']length[\"\']")" ]
	then
		duracion=$(echo "$linea" | grep -E "id=[\"\']length[\"\']" | sed -r -n -e 's/.+>([0-9]+)m?<.+/Duración: \1 minutos/p')
	fi

	#Sinopsis
	if [ -n "$(echo "$linea" | grep -E "<p>.+<\/p>")" ]
	then
		sinopsis=$(echo "$linea" | grep -E "<p>.+<\/p>" | sed -r -n -e 's/<p>(.+)<\/p>/Sinopsis: \1/p')
	fi


	#Género
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']genres[\"\']")" ]
	then
		genero=$(echo "$linea" | grep -E "id=[\"\']genres[\"\']" | sed -r -n -e 's/<p.+>(.+)<.+/Géneros: \1/p' | sed -r -e 's/( \|)/, /g')
	fi
	

	#Director
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']director[\"\']")" ]
	then
		director=$(echo "$linea" | grep -E "id=[\"\']director[\"\']"| sed -r -n -e 's/<p.+>(.+)<.+/Director: \1/p')
	fi
	

	#Guionista
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']writers[\"\']")" ]
	then
		guionista=$(echo "$linea" | grep -E "id=[\"\']writers[\"\']"| sed -r -n -e 's/<[pP].+>(.+)<.+/Gionista\/s: \1/p')
	fi
	

	#fin
	fin=$(echo "$linea" | grep -E '</article>')

	if [ -n "$fin" ]
	then
		echo "======================================================"
		echo "$titulo"
		echo "$anio"
		echo "Valoración: $nota ($valoraciones valoraciones)"
		echo "$duracion"
		echo "$sinopsis"
		echo "$genero"
		echo "$director"
		echo "$guionista"
		echo ""

		linea=""
		titulo=""
		anio=""
		nota=""
		duracion=""
		sinopsis=""
		genero=""
		director=""
		guionista=""
		fin=""
	fi

done < films.html

echo "2) Mostrar el título, el año y la valoración de las películas de los años 2000 (2000-2009)"
echo ""

while read linea
do
	#Linea del principio
	if [ -n "$(echo "$linea" | grep -E '<article>')" ]
	then
		linea=$(echo "$linea" | grep -E '<article>' | sed -r -n -e 's/(.+)/=========================================/p')
	fi


	#Título
	if [ -n "$(echo "$linea" | grep -E -i '<h2>')" ]
	then
		titulo=$(echo "$linea" | grep -E -i '<h2>' | sed -r -n -e 's/.+>(.+) \([0-9]+\)<.+/Título: \1/p')
	fi


	#Año
	if [ -n "$(echo "$linea" | grep -E -i "<h2>")" ]
	then
		anio=$(echo "$linea" | grep -E -i "<h2>" | sed -r -n -e 's/.+>.+ \(([0-9]+)\)<.+/\1/p')
	fi


	#Valoración
	if [ -n "$(echo "$linea" | grep -E "id=\"rating\"")" ]
	then
		nota=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\1/p')
		if [ -n "$nota" ]
		then
			valoraciones=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\3/p')
		fi
	fi


	#duración
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']length[\"\']")" ]
	then
		duracion=$(echo "$linea" | grep -E "id=[\"\']length[\"\']" | sed -r -n -e 's/.+>([0-9]+)m?<.+/Duración: \1 minutos/p')
	fi

	#Sinopsis
	if [ -n "$(echo "$linea" | grep -E "<p>.+<\/p>")" ]
	then
		sinopsis=$(echo "$linea" | grep -E "<p>.+<\/p>" | sed -r -n -e 's/<p>(.+)<\/p>/Sinopsis: \1/p')
	fi


	#Género
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']genres[\"\']")" ]
	then
		genero=$(echo "$linea" | grep -E "id=[\"\']genres[\"\']" | sed -r -n -e 's/<p.+>(.+)<.+/Géneros: \1/p' | sed -r -e 's/( \|)/, /g')
	fi
	

	#Director
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']director[\"\']")" ]
	then
		director=$(echo "$linea" | grep -E "id=[\"\']director[\"\']"| sed -r -n -e 's/<p.+>(.+)<.+/Director: \1/p')
	fi
	

	#Guionista
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']writers[\"\']")" ]
	then
		guionista=$(echo "$linea" | grep -E "id=[\"\']writers[\"\']"| sed -r -n -e 's/<[pP].+>(.+)<.+/Gionista\/s: \1/p')
	fi
	

	#fin
	fin=$(echo "$linea" | grep -E '</article>')

	if [ -n "$fin" ]
	then
		if [ $anio -ge 2000 -a $anio -le 2009 ]
		then
			echo "======================================================"
			echo "$titulo"
			echo "Año: $anio"
			echo "Valoración: $nota ($valoraciones valoraciones)"
			echo "$duracion"
			echo "$sinopsis"
			echo "$genero"
			echo "$director"
			echo "$guionista"
			echo ""

			linea=""
			titulo=""
			anio=""
			nota=""
			duracion=""
			sinopsis=""
			genero=""
			director=""
			guionista=""
			fin=""
		fi
	fi

done < films.html


echo "3) Mostrar las películas formatadas como en 1) pero cambiando el formato del número de valoraciones de 658000 a 658k"
echo ""

while read linea
do
	#Linea del principio
	if [ -n "$(echo "$linea" | grep -E '<article>')" ]
	then
		linea=$(echo "$linea" | grep -E '<article>' | sed -r -n -e 's/(.+)/=========================================/p')
	fi


	#Título
	if [ -n "$(echo "$linea" | grep -E -i '<h2>')" ]
	then
		titulo=$(echo "$linea" | grep -E -i '<h2>' | sed -r -n -e 's/.+>(.+) \([0-9]+\)<.+/Título: \1/p')
	fi


	#Año
	if [ -n "$(echo "$linea" | grep -E -i "<h2>")" ]
	then
		anio=$(echo "$linea" | grep -E -i "<h2>" | sed -r -n -e 's/.+>.+ \(([0-9]+)\)<.+/Año: \1/p')
	fi


	#Valoración
	if [ -n "$(echo "$linea" | grep -E "id=\"rating\"")" ]
	then
		nota=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\1/p')
		if [ -n "$nota" ]
		then
			valoraciones=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\3/p')
			ceros=$(echo $valoraciones | sed -r -n -e 's/(.+)(000)/\1K/p')
		fi
	fi


	#duración
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']length[\"\']")" ]
	then
		duracion=$(echo "$linea" | grep -E "id=[\"\']length[\"\']" | sed -r -n -e 's/.+>([0-9]+)m?<.+/Duración: \1 minutos/p')
	fi

	#Sinopsis
	if [ -n "$(echo "$linea" | grep -E "<p>.+<\/p>")" ]
	then
		sinopsis=$(echo "$linea" | grep -E "<p>.+<\/p>" | sed -r -n -e 's/<p>(.+)<\/p>/Sinopsis: \1/p')
	fi


	#Género
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']genres[\"\']")" ]
	then
		genero=$(echo "$linea" | grep -E "id=[\"\']genres[\"\']" | sed -r -n -e 's/<p.+>(.+)<.+/Géneros: \1/p' | sed -r -e 's/( \|)/, /g')
	fi
	

	#Director
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']director[\"\']")" ]
	then
		director=$(echo "$linea" | grep -E "id=[\"\']director[\"\']"| sed -r -n -e 's/<p.+>(.+)<.+/Director: \1/p')
	fi
	

	#Guionista
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']writers[\"\']")" ]
	then
		guionista=$(echo "$linea" | grep -E "id=[\"\']writers[\"\']"| sed -r -n -e 's/<[pP].+>(.+)<.+/Gionista\/s: \1/p')
	fi
	

	#fin
	fin=$(echo "$linea" | grep -E '</article>')

	if [ -n "$fin" ]
	then
		echo "======================================================"
		echo "$titulo"
		echo "$anio"
		if [ -z "$ceros" ]
		then
			echo "Valoración: $nota ($valoraciones valoraciones)."
		else
			echo "Valoración: $nota ($ceros valoraciones)."
		fi
		echo "$duracion"
		echo "$sinopsis"
		echo "$genero"
		echo "$director"
		echo "$guionista"
		echo ""

		linea=""
		titulo=""
		anio=""
		nota=""
		duracion=""
		sinopsis=""
		genero=""
		director=""
		guionista=""
		fin=""
	fi

done < films.html


echo "4) Añadir un punto al final de las líneas que no lo tengan."
echo ""

while read linea
do
	#Linea del principio
	if [ -n "$(echo "$linea" | grep -E '<article>')" ]
	then
		linea=$(echo "$linea" | grep -E '<article>' | sed -r -n -e 's/(.+)/=========================================/p')
	fi


	#Título
	if [ -n "$(echo "$linea" | grep -E -i '<h2>')" ]
	then
		titulo=$(echo "$linea" | grep -E -i '<h2>' | sed -r -n -e 's/.+>(.+) \([0-9]+\)<.+/Título: \1/p')
	fi


	#Año
	if [ -n "$(echo "$linea" | grep -E -i "<h2>")" ]
	then
		anio=$(echo "$linea" | grep -E -i "<h2>" | sed -r -n -e 's/.+>.+ \(([0-9]+)\)<.+/Año: \1/p')
	fi


	#Valoración
	if [ -n "$(echo "$linea" | grep -E "id=\"rating\"")" ]
	then
		nota=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\1/p')
		if [ -n "$nota" ]
		then
			valoraciones=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\3/p')
		fi
	fi


	#duración
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']length[\"\']")" ]
	then
		duracion=$(echo "$linea" | grep -E "id=[\"\']length[\"\']" | sed -r -n -e 's/.+>([0-9]+)m?<.+/Duración: \1 minutos/p')
	fi

	#Sinopsis
	if [ -n "$(echo "$linea" | grep -E "<p>.+<\/p>")" ]
	then
		sinopsis=$(echo "$linea" | grep -E "<p>.+<\/p>" | sed -r -n -e 's/<p>(.+)<\/p>/Sinopsis: \1/p')
	fi


	#Género
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']genres[\"\']")" ]
	then
		genero=$(echo "$linea" | grep -E "id=[\"\']genres[\"\']" | sed -r -n -e 's/<p.+>(.+)<.+/Géneros: \1/p' | sed -r -e 's/( \|)/, /g')
	fi
	

	#Director
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']director[\"\']")" ]
	then
		director=$(echo "$linea" | grep -E "id=[\"\']director[\"\']"| sed -r -n -e 's/<p.+>(.+)<.+/Director: \1/p')
	fi
	

	#Guionista
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']writers[\"\']")" ]
	then
		guionista=$(echo "$linea" | grep -E "id=[\"\']writers[\"\']"| sed -r -n -e 's/<[pP].+>(.+)<.+/Gionista\/s: \1/p')
	fi
	

	#fin
	fin=$(echo "$linea" | grep -E '</article>')

	if [ -n "$fin" ]
	then
		echo "======================================================"
		echo "$titulo."
		echo "$anio."
		echo "Valoración: $nota ($valoraciones valoraciones)."
		echo "$duracion."
		echo "$sinopsis."
		echo "$genero."
		echo "$director."
		echo "$guionista."
		echo ""

		linea=""
		titulo=""
		anio=""
		nota=""
		duracion=""
		sinopsis=""
		genero=""
		director=""
		guionista=""
		fin=""
	fi

done < films.html



echo "5) Mostrar una versión resumida en la que la sinopsis se limita a 300 caracteres."
echo ""

while read linea
do
	#Linea del principio
	if [ -n "$(echo "$linea" | grep -E '<article>')" ]
	then
		linea=$(echo "$linea" | grep -E '<article>' | sed -r -n -e 's/(.+)/=========================================/p')
	fi


	#Título
	if [ -n "$(echo "$linea" | grep -E -i '<h2>')" ]
	then
		titulo=$(echo "$linea" | grep -E -i '<h2>' | sed -r -n -e 's/.+>(.+) \([0-9]+\)<.+/Título: \1/p')
	fi


	#Año
	if [ -n "$(echo "$linea" | grep -E -i "<h2>")" ]
	then
		anio=$(echo "$linea" | grep -E -i "<h2>" | sed -r -n -e 's/.+>.+ \(([0-9]+)\)<.+/Año: \1/p')
	fi


	#Valoración
	if [ -n "$(echo "$linea" | grep -E "id=\"rating\"")" ]
	then
		nota=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\1/p')
		if [ -n "$nota" ]
		then
			valoraciones=$(echo "$linea" | grep -E "id=\"rating\"" | sed -r -n -e 's/.+>([0-9]\.[0-9])(\/10)? *\((.+) ratings.+/\3/p')
		fi
	fi


	#duración
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']length[\"\']")" ]
	then
		duracion=$(echo "$linea" | grep -E "id=[\"\']length[\"\']" | sed -r -n -e 's/.+>([0-9]+)m?<.+/Duración: \1 minutos/p')
	fi

	#Sinopsis
	if [ -n "$(echo "$linea" | grep -E "<p>.+<\/p>")" ]
	then
		sinopsis=$(echo "$linea" | grep -E "<p>.+<\/p>" | sed -r -n -e 's/<p>(.{1,300}).*<\/p>/Sinopsis: \1.../p')
	fi


	#Género
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']genres[\"\']")" ]
	then
		genero=$(echo "$linea" | grep -E "id=[\"\']genres[\"\']" | sed -r -n -e 's/<p.+>(.+)<.+/Géneros: \1/p' | sed -r -e 's/( \|)/, /g')
	fi
	

	#Director
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']director[\"\']")" ]
	then
		director=$(echo "$linea" | grep -E "id=[\"\']director[\"\']"| sed -r -n -e 's/<p.+>(.+)<.+/Director: \1/p')
	fi
	

	#Guionista
	if [ -n "$(echo "$linea" | grep -E "id=[\"\']writers[\"\']")" ]
	then
		guionista=$(echo "$linea" | grep -E "id=[\"\']writers[\"\']"| sed -r -n -e 's/<[pP].+>(.+)<.+/Gionista\/s: \1/p')
	fi
	

	#fin
	fin=$(echo "$linea" | grep -E '</article>')

	if [ -n "$fin" ]
	then
		echo "======================================================"
		echo "$titulo"
		echo "$anio"
		echo "Valoración: $nota ($valoraciones valoraciones)"
		echo "$duracion"
		echo "$sinopsis"
		echo "$genero"
		echo "$director"
		echo "$guionista"
		echo ""

		linea=""
		titulo=""
		anio=""
		nota=""
		duracion=""
		sinopsis=""
		genero=""
		director=""
		guionista=""
		fin=""
	fi

done < films.html
