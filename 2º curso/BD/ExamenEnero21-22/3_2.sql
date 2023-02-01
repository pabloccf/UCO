-- Ejercicio 3.2
set serveroutput on;
DECLARE
    CURSOR c IS SELECT dni, SUBSTR(nombreCompleto, 1, INSTR(nombreCompleto, ' ') - 1) Nombre, 
        SUBSTR(nombreCompleto, INSTR(nombreCompleto, ' '), LENGTH(nombreCompleto)) Apellidos, fechaNacimiento, email, 
            estudiosSuperiores FROM votantes WHERE fechaNacimiento > '31/12/1989';
    sueldo NUMBER := 0;
    dinero NUMBER := 0;
BEGIN
    FOR num_row IN c LOOP
        IF num_row.estudiosSuperiores LIKE 'Ninguno' THEN
            sueldo := LENGTH(num_row.Nombre) * 50;
            INSERT INTO jovenes VALUES(num_row.dni, num_row.Nombre, num_row.Apellidos, sueldo, num_row.fechaNacimiento, num_row.email);
        END IF;
        IF num_row.estudiosSuperiores LIKE 'Basicos' THEN
            sueldo := LENGTH(num_row.Nombre) * 100;
            INSERT INTO jovenes VALUES(num_row.dni, num_row.Nombre, num_row.Apellidos, sueldo, num_row.fechaNacimiento, num_row.email);
        END IF;
        IF num_row.estudiosSuperiores LIKE 'Superiores' THEN
            sueldo := LENGTH(num_row.Nombre) * 150;
            INSERT INTO jovenes VALUES(num_row.dni, num_row.Nombre, num_row.Apellidos, sueldo, num_row.fechaNacimiento, num_row.email);
        END IF;
        IF num_row.estudiosSuperiores LIKE 'Doctorado' THEN
            sueldo := LENGTH(num_row.Nombre) * 200;
            INSERT INTO jovenes VALUES(num_row.dni, num_row.Nombre, num_row.Apellidos, sueldo, num_row.fechaNacimiento, num_row.email);
        END IF;
        dinero := sueldo + dinero;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Se necesita ' || dinero || '€ para pagar las nominas');
END;