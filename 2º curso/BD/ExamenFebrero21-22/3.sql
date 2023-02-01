-- Ejercicio 3
set serveroutput on;
DECLARE
    CURSOR c IS SELECT v.nombreCompleto, p.comunidad, p.numeroHabitantes FROM votantes v, provincias p, localidades l 
        WHERE l.provincia = p.idProvincia AND l.idLocalidad LIKE DECODE(v.localidad, 1, 9, 2, 9, 3, 9, v.localidad);
    nHabitantesM NUMBER := 0;
    nHabitantesA NUMBER := 0;
    votantesM NUMBER := 0;
    votantesA NUMBER := 0;
BEGIN
    FOR num_row IN c LOOP
        DBMS_OUTPUT.PUT_LINE(num_row.nombreCompleto || ' es de ' || num_row.comunidad);
        IF num_row.comunidad LIKE 'Madrid' THEN
            votantesM := votantesM + 1;
            nHabitantesM := num_row.numeroHabitantes;
        END IF;
        IF num_row.comunidad LIKE 'Andalucia' THEN
            votantesA := votantesA + 1;
            nHabitantesA := num_row.numeroHabitantes;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Hay ' || votantesM || ' votantes de Madrid y tiene una representacion de ' || votantesM/nHabitantesM);
    DBMS_OUTPUT.PUT_LINE('Hay ' || votantesA || ' votantes de Andalucia y tiene una representacion de ' || votantesA/nHabitantesA);
END;