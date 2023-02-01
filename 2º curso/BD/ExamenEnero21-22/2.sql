-- Ejercicio 2
SELECT p.nombreCompleto "Nombre partido", AVG(cd.certidumbre) "Certidumbre media"
FROM partidos p, consultas_datos cd
WHERE cd.partido = p.idPartido AND p.fechaCreacion NOT LIKE 
    (SELECT MAX(p1.fechaCreacion) FROM partidos p1 WHERE p1.fechaCreacion < (SELECT MAX(p2.fechaCreacion) FROM partidos p2)) 
    AND p.fechaCreacion NOT LIKE (SELECT MAX(p3.fechaCreacion) FROM partidos p3)
GROUP BY p.nombreCompleto
ORDER BY AVG(cd.certidumbre) ASC;