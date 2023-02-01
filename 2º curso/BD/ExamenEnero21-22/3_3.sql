-- Ejercicio 3.3
set serveroutput on;
DECLARE
    CURSOR c IS SELECT SUBSTR(v.nombreCompleto, 1, INSTR(v.nombreCompleto, ' ') - 1) NombrePila, v.dni, l.nombre 
        FROM votantes v, localidades l WHERE v.localidad = l.idLocalidad ORDER BY v.dni DESC;
    persona votantes.nombreCompleto%type;
    ciudad localidades.nombre%type;
    dniP votantes.dni%type;
BEGIN
    FOR num_row IN c LOOP
        IF persona IS NULL THEN
            persona := num_row.NombrePila;
            ciudad := num_row.nombre;
            dniP := num_row.dni;
        ELSE
            DBMS_OUTPUT.PUT_LINE(persona || ' de ' || ciudad || ' va antes que ' || num_row.NombrePila || ' de ' || num_row.nombre);
            persona := num_row.NombrePila;
            ciudad := num_row.nombre;
            dniP := num_row.dni;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(dniP || ' es el DNI mas pequeño');
END;