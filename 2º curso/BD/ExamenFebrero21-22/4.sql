-- Ejercicio 4
set serveroutput on;
DECLARE
    CURSOR c IS SELECT dni FROM votantes ORDER BY dni DESC;
    dniP votantes.dni%type;
BEGIN
    FOR num_row IN c LOOP
        IF dniP IS NULL THEN
            dniP := num_row.dni;
        ELSE
            IF MOD(dniP, 2) = 0 AND MOD(num_row.dni, 2) = 0 THEN
                DBMS_OUTPUT.PUT_LINE('El DNI ' || dniP || ' va antes que el DNI ' || num_row.dni);
                dniP := num_row.dni;
            END IF;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('El DNI ' || dniP || ' es el mas pequeño');
END;