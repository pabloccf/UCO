-- Ejercicio 1
SELECT v.nombreCompleto "Nombre votantes", COUNT(c.votante) "Nº consultas"
FROM votantes v, consultas c
WHERE v.dni = c.votante AND v.dni LIKE '%10%'
GROUP BY v.nombreCompleto
HAVING COUNT(c.votante) > 3
ORDER BY COUNT(c.votante) ASC;