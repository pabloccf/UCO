-- Ejercicio 1
SELECT v.nombreCompleto FROM votantes v
JOIN localidades l ON v.localidad = l.idLocalidad
WHERE SUBSTR(to_char(v.dni), -1, 1) LIKE (to_char(l.idLocalidad) + 1);

-- Ejercicio 2
SELECT v.nombreCompleto, l.nombre FROM votantes v, localidades l
WHERE l.idLocalidad LIKE DECODE(v.localidad, 1, 9, 2, 9, 3, 9, v.localidad);

-- Ejercicio 3
SELECT p.siglas "siglas" FROM partidos p, eventos_resultados er
WHERE er.partido = p.idPartido
GROUP BY p.siglas
HAVING COUNT(er.partido) = (SELECT MAX(COUNT(er.partido)) FROM partidos p, eventos_resultados er
WHERE er.partido = p.idPartido 
GROUP BY p.siglas);

-- Ejercicio 4
SELECT v.dni "DNI" FROM votantes v
WHERE v.fechaNacimiento = (SELECT MIN(v.fechaNacimiento) FROM votantes v 
WHERE v.fechaNacimiento > (SELECT MIN(v.fechaNacimiento) FROM votantes v));

-- Ejercicio 5
SELECT v.dni "DNI", COUNT(c.votante) FROM votantes v
JOIN consultas c ON v.dni = c.votante
GROUP BY v.dni ORDER BY COUNT(c.votante) DESC;

-- Ejercicio 6
SELECT v.dni "DNI", COUNT(c.votante) FROM votantes v
JOIN consultas c ON v.dni = c.votante
GROUP BY v.dni
HAVING COUNT(c.votante) > (SELECT AVG(COUNT(c.votante)) FROM consultas c
GROUP BY c.votante)
ORDER BY COUNT(c.votante) DESC;

-- Ejercicio 7
SELECT v.nombreCompleto "Nombre completo" FROM votantes v
JOIN consultas c ON v.dni = c.votante
GROUP BY v.nombreCompleto
HAVING COUNT(c.votante) > (SELECT AVG(COUNT(c.votante)) 
FROM consultas c GROUP BY c.votante);

-- Ejercicio 8
SELECT v.dni "DNI", COUNT(c.votante) FROM votantes v
JOIN consultas c ON v.dni = c.votante
WHERE v.dni NOT LIKE (SELECT v.dni FROM votantes v WHERE v.fechaNacimiento = 
(SELECT MIN(v.fechaNacimiento) FROM votantes v
WHERE v.fechaNacimiento > (SELECT MIN(v.fechaNacimiento) FROM votantes v)))
GROUP BY v.dni
ORDER BY COUNT(c.votante) DESC;