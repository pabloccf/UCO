-- Ejercicio 1
SELECT p.nombreCompleto "Partido", COUNT(cd.partido) "Nº consultas"
FROM partidos p, consultas_datos cd
WHERE cd.partido = p.idPartido AND cd.respuesta = 'No' AND cd.certidumbre > 0.1 AND cd.certidumbre < 0.6
GROUP BY p.nombreCompleto;