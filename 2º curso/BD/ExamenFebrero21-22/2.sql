-- Ejercicio 2
SELECT l.nombre "Localidades"
FROM localidades l, votantes v
WHERE v.localidad = l.idLocalidad
GROUP BY l.nombre
HAVING AVG(DECODE(v.estudiosSuperiores, 'Ninguno', 0, 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3)) > 
    (SELECT AVG(DECODE(v1.estudiosSuperiores, 'Ninguno', 0, 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3)) 
        FROM votantes v1, localidades l1, provincias p1 WHERE v1.localidad = l1.idLocalidad AND l1.provincia = p1.idProvincia);