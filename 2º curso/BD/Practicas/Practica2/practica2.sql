-- Ejercicio 1
SELECT nombreCompleto FROM votantes WHERE nombreCompleto LIKE "%n";

-- Ejercicio 2
SELECT dni FROM votantes WHERE dni LIKE "%5%5%5";

-- Ejercicio 3
SELECT nombreCompleto FROM votantes WHERE fechaNacimiento > '1/01/1990';

-- Ejercicio 4
SELECT v.nombreCompleto, l.nombre FROM votantes v, localidades l 
WHERE v.localidad = l.idLocalidad AND l.numeroHabitantes > '300000';

-- Ejercicio 5
SELECT v.nombreCompleto, p.comunidad FROM votantes v, provincias p, localidades l
WHERE v.localidad = l.idLocalidad AND l.provincia = p.idProvincia AND p.numeroHabitantes > '300000';

-- Ejercicio 6
SELECT p.idPartido, COUNT(cd.partido) FROM consultas_datos cd, partidos p, consultas c
WHERE cd.partido = p.idPartido AND cd.consulta = c.idConsulta GROUP BY partido;

-- Ejercicio 7
SELECT p.idPartido, COUNT(cd.partido) FROM partidos p, consultas_datos cd, consultas c
WHERE cd.partido = p.idPartido AND cd.consulta = c.idConsulta GROUP BY partido;

-- Ejercicio 8
SELECT p.nombreCompleto FROM partidos p, consultas_datos cd, consultas c
WHERE cd.partido = p.idPartido AND cd.consulta = c.idConsulta GROUP BY p.nombreCompleto
HAVING COUNT(cd.partido) > 10;

-- Ejercicio 9
SELECT p.nombreCompleto, COUNT(cd.partido) FROM partidos p, consultas_datos cd, consultas c
WHERE cd.partido = p.idPartido AND cd.consulta = c.idConsulta 
GROUP BY cd.partido
HAVING COUNT(cd.partido) > 10;

-- Ejercicio 10
SELECT p.nombreCompleto, COUNT(cd.partido) FROM partidos p, consultas_datos cd, consultas c
WHERE cd.partido = p.idPartido AND cd.consulta = c.idConsulta 
AND cd.certidumbre > '0.8' AND cd.respuesta = 'Si'
GROUP BY cd.partido;