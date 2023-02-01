-- Ejercicio 1
SELECT dni FROM votantes WHERE telefono LIKE '%6%6%' AND telefono NOT LIKE '%6%6%6%';

-- Ejercicio 2
SELECT dni FROM votantes
WHERE telefono LIKE '%6%6%6%' AND telefono NOT LIKE '%6%6%6%6%';

-- Ejercicio 3
SELECT l.nombre, p.nombre FROM localidades l
JOIN provincias p ON l.provincia = p.idProvincia
WHERE SUBSTR(to_char(l.numeroHabitantes), -1, 1) LIKE to_char(l.provincia);

-- Ejercicio 4
SELECT nombreCompleto FROM votantes
WHERE SUBSTR(to_char(telefono), -1, 1) LIKE SUBSTR(to_char(dni), -1, 1);

-- Ejercicio 5
SELECT nombreCompleto FROM votantes
WHERE nombreCompleto LIKE '%s%' AND fechaNacimiento < '12/02/1990';

-- Ejercicio 6
SELECT DISTINCT votante FROM consultas
ORDER BY votante DESC;

-- Ejercicio 7
SELECT v.dni FROM votantes v
JOIN consultas c ON v.dni = c.votante
GROUP BY v.dni HAVING COUNT(c.evento) > 3;

-- Ejercicio 8
SELECT v.nombreCompleto, COUNT(c.evento) FROM votantes v
JOIN consultas c ON v.dni = c.votante
GROUP BY v.nombreCompleto HAVING COUNT (c.evento) > 3 ORDER BY COUNT(c.evento) ASC;

-- Ejercicio 9
SELECT v.nombreCompleto, l.nombre FROM votantes v, localidades l
WHERE v.localidad = l.idLocalidad AND l.numeroHabitantes > 300000;

-- Ejercicio 10
SELECT p.nombreCompleto, MAX(cd.certidumbre) FROM partidos p
JOIN consultas_datos cd ON cd.partido = p.idPartido
GROUP BY p.nombreCompleto;

-- Ejercicio 11
SELECT v.nombreCompleto, AVG(cd.certidumbre) FROM votantes v
JOIN consultas c ON v.dni = c.votante 
JOIN consultas_datos cd ON cd.consulta = c.idConsulta
WHERE cd.respuesta = 'Si'
GROUP BY v.nombreCompleto;

-- Ejercicio 12
SELECT v.nombreCompleto, AVG(cd.certidumbre) FROM votantes v
JOIN consultas c ON v.dni = c.votante
JOIN consultas_datos cd ON cd.consulta = c.idConsulta
WHERE cd.respuesta = 'Si'
HAVING AVG(cd.certidumbre) > 0.5 AND AVG(cd.certidumbre) < 0.8
GROUP BY v.nombreCompleto;

-- Ejercicio 13
SELECT p.nombreCompleto, AVG(cd.certidumbre) FROM partidos p
JOIN consultas_datos cd ON cd.partido = p.idPartido
WHERE cd.respuesta = 'No'
HAVING AVG(cd.certidumbre) > 0.6
GROUP BY p.nombreCompleto;