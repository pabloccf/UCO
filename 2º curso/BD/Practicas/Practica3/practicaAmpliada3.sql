-- Ejercicio 1
SELECT SUBSTR(v.nombreCompleto, 1, INSTR(v.nombreCompleto, ' ') - 1) "Nombre de pila", l.nombre "Localidad", p.comunidad "Comunidad"
FROM votantes v, localidades l, provincias p
WHERE v.localidad = l.idLocalidad AND l.provincia = p.idProvincia AND l.idLocalidad IN (1, 3, 9);

-- Ejercicicio 2
SELECT l.nombre || ' va antes que ' || l1.nombre "Ordenacion"
FROM localidades l, localidades l1
WHERE l.idLocalidad + 1= l1.idLocalidad;

-- Ejercicio 3
SELECT l.nombre
FROM localidades l
WHERE l.numeroHabitantes > 
((SELECT l1.numeroHabitantes FROM localidades l1, votantes v1 WHERE v1.localidad = l1.idLocalidad AND v1.fechaNacimiento = (SELECT MIN(v2.fechaNacimiento) FROM votantes v2
WHERE v2.fechaNacimiento > (SELECT MIN(v3.fechaNacimiento) FROM votantes v3)))) GROUP BY l.nombre;

-- Ejercicio 4
SELECT v.nombreCompleto "Nombre", v.localidad "Numero localidad", DECODE(SIGN(18 - ((SYSDATE - v.fechaNacimiento)/ 365.6)), 1, 'Menor de edad', 'Mayor de edad') "Mayoria de edad"
FROM votantes v
WHERE v.localidad IN (2, 4, 8)
ORDER BY "Mayoria de edad";

-- Ejercicio 5
SELECT l.nombre "Localidad", l.numeroHabitantes "Numero de habitantes", p.nombre "Comunidad"
FROM localidades l, provincias p
WHERE l.provincia = p.idProvincia AND p.idProvincia IN (1, 2, 3) AND l.numeroHabitantes > 
ANY(SELECT l.numeroHabitantes FROM localidades l WHERE l.provincia = '4');

-- Ejercicio 6
SELECT v.nombreCompleto
FROM votantes v, consultas c
WHERE v.dni = c.votante AND v.situacionLaboral = 'Activo'
GROUP BY v.nombreCompleto
HAVING COUNT(c.evento) < AVG(c.evento);

-- Ejercicio 7
SELECT l.nombre
FROM localidades l, votantes v
WHERE v.localidad = l.idLocalidad 
GROUP BY l.nombre
ORDER BY AVG(DECODE(v.estudiosSuperiores, 'Ninguno', 0, 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3)) DESC;

-- Ejercicio 8
SELECT l.nombre
FROM localidades l, votantes v
WHERE v.localidad = l.idLocalidad
HAVING AVG(DECODE(v.estudiosSuperiores, 'Ninguno', 0, 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3)) >
ALL(SELECT AVG(DECODE(v.estudiosSuperiores, 'Ninguno', 0, 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3)) 
FROM localidades l, votantes v WHERE v.localidad = l.idLocalidad GROUP BY l.provincia)
GROUP BY l.nombre;