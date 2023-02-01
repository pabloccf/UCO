-- Ejercicio 1
set serveroutput on;
DECLARE
    conteo NUMBER:=0;
    CURSOR c IS SELECT * FROM votantes WHERE SUBSTR(dni, -length(localidad + 1), length(localidad + 1)) LIKE localidad +1;
BEGIN
    FOR num_row IN c LOOP
        DBMS_OUTPUT.PUT_LINE(num_row.nombreCompleto);
        conteo:=conteo + 1;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Hay un total de ' || conteo || ' votantes');
END;

-- Ejercicio 2
set serveroutput on;
DECLARE
    conteo NUMBER:=0;
    CURSOR c IS SELECT nombreCompleto FROM votantes WHERE SUBSTR(dni, length(dni), length(dni)) = localidad + 1;
    fila c%rowtype;
BEGIN
    open c;
    LOOP
        FETCH c INTO fila;
        EXIT WHEN c%notfound;
        conteo := conteo + 1;
        DBMS_OUTPUT.PUT_LINE(fila.nombreCompleto);
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Hay un total de ' || conteo || ' votantes');
END;

-- Ejercicio 3
set serveroutput on;
DECLARE
    conteo NUMBER:=0;
    CURSOR c IS SELECT nombreCompleto FROM votantes WHERE SUBSTR(dni, length(dni), length(dni)) = localidad +1;
    fila c%rowtype;
BEGIN
    open c;
    FETCH c INTO fila;
    WHILE c%found LOOP
        conteo := conteo + 1;
        DBMS_OUTPUT.PUT_LINE(fila.nombreCompleto);
        FETCH c INTO fila;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Hay un total de ' || conteo || ' votantes');
END;

-- Ejercicio 4
set serveroutput on;
DECLARE
    CURSOR c IS SELECT v.nombreCompleto, l.nombre FROM votantes v, localidades l WHERE l.idLocalidad
    LIKE DECODE(v.localidad, 1, 9, 2, 9, 3, 9, v.localidad);
    conteo NUMBER:=0;
BEGIN
    FOR num_row IN c LOOP
        DBMS_OUTPUT.PUT_LINE(num_row.nombreCompleto || ' es de ' || num_row.nombre);
        IF num_row.nombre LIKE 'Madrid' THEN
            conteo := conteo + 1;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Hay un total de ' || conteo || ' votantes de Madrid');
END;

-- Ejercicio 5
set serveroutput on;
DECLARE
    CURSOR c IS SELECT dni FROM votantes ORDER BY dni DESC;
    dniP votantes.dni%type;
BEGIN
    FOR num_row IN c LOOP
        IF dniP IS NULL THEN 
            dniP := num_row.dni;
        ELSE
            DBMS_OUTPUT.PUT_LINE(dniP || ' va antes que ' || num_row.dni);
            dniP := num_row.dni;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(dniP || ' es el menor');
END;

-- Ejercicio 6
set serveroutput on;
DECLARE
    CURSOR c IS SELECT dni, COUNT(votante) nVeces FROM votantes JOIN consultas ON votantes.dni = consultas.votante GROUP BY dni
    HAVING COUNT(votante) > (SELECT AVG(COUNT(votante)) FROM consultas GROUP BY votante) ORDER BY COUNT(votante) DESC;
BEGIN
    FOR num_row IN c LOOP
        DBMS_OUTPUT.PUT_LINE(num_row.dni || ' ha participado ' || num_row.nVeces || ' veces');
    END LOOP;
END;

-- Ejercicio 7
CREATE TABLE votantesAntiguos(
dni NUMBER(8,0),
nombreCompleto VARCHAR2(255),
email VARCHAR2(255),
fechaNacimiento DATE,
sueldo NUMBER
);
set serveroutput on;
DECLARE 
    CURSOR c IS SELECT dni, nombreCompleto, email, fechaNacimiento FROM votantes WHERE fechaNacimiento < '01/01/1980';
    conteo NUMBER := 0;
BEGIN
    FOR num_row IN c LOOP
        IF num_row.situacionLaboral LIKE 'Activo' THEN
            DBMS_OUTPUT.PUT_LINE(num_row.nombreCompleto);
            INSERT INTO votantesAntiguos
            VALUES(num_row.dni, num_row.nombreCompleto, num_row.email, num_row.fechaNacimiento, 1500);
            conteo := conteo + 1;
        ELSE
            DBMS_OUTPUT.PUT_LINE(num_row.nombreCompleto);
            INSERT INTO votantesAntiguos
            VALUES(num_row.dni, num_row.nombreCompleto, num_row.email, num_row.fechaNacimiento, 0);
            conteo := conteo + 1;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Se han insertado un total de ' || conteo || ' votantes');
END;