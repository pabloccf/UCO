-- Ejercicio 1
set serveroutput on;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Hola mundo, hoy es el día ' || CURRENT_DATE);
END;

-- Ejercicio 2
set serveroutput on;
DECLARE
    v_nombre votantes.nombreCompleto%type;
    v_correo votantes.email%type;
    buscar NUMBER:=30983712;
BEGIN
    SELECT nombreCompleto, email INTO v_nombre, v_correo FROM votantes WHERE dni = buscar;
    DBMS_OUTPUT.PUT_LINE(v_nombre || ' con correo: ' || v_correo);
END;

-- Ejercicio 3
set serveroutput on;
DECLARE
    v_nombre votantes.nombreCompleto%type;
    v_correo votantes.email%type;
    buscar NUMBER:=30983712;
BEGIN
    SELECT SUBSTR(nombreCompleto, 1, INSTR(nombreCompleto, ' ') -1), email INTO v_nombre, v_correo FROM votantes WHERE dni = buscar;
    DBMS_OUTPUT.PUT_LINE(v_nombre || ' con correo: ' || v_correo);
END;

-- Ejercicio 4
set serveroutput on;
DECLARE 
    v_nombre votantes.nombreCompleto%type;
    buscar NUMBER:=30983712;
BEGIN
    SELECT('Pepe' || SUBSTR(nombreCompleto, INSTR(nombreCompleto, ' '))) INTO v_nombre FROM votantes WHERE dni = buscar;
    DBMS_OUTPUT.PUT_LINE(v_nombre);
END;

-- Ejercicio 5
set serveroutput on;
DECLARE
    v_nombre votantes.nombreCompleto%type;
    v_dni votantes.dni%type;
BEGIN
    SELECT nombreCompleto, dni INTO v_nombre, v_dni FROM votantes WHERE fechaNacimiento = 
    (SELECT MIN(fechaNacimiento) FROM votantes);
    DBMS_OUTPUT.PUT_LINE('El señor ' || v_nombre || ' con dni ' || v_dni || ' es el votante mas longevo');
END;

-- Ejercicio 6
set serveroutput on;
DECLARE
    v_nombre1 votantes.nombreCompleto%type;
    v_email1 votantes.email%type;
    v_nombre2 votantes.nombreCompleto%type;
    v_email2 votantes.email%type;
BEGIN
    SELECT nombreCompleto, SUBSTR(email, 1, INSTR(email, '@')) INTO v_nombre1, v_email1 FROM votantes WHERE fechaNacimiento = 
    (SELECT MIN(fechaNacimiento) FROM votantes);
    DBMS_OUTPUT.PUT_LINE(v_nombre1 || ' -- Email: ' || v_email1 || 'uco.es');
    SELECT nombreCompleto, SUBSTR(email, 1, INSTR(email, '@')) INTO v_nombre2, v_email2 FROM votantes WHERE fechaNacimiento = 
    (SELECT MAX(fechaNacimiento) FROM votantes);
    DBMS_OUTPUT.PUT_LINE(v_nombre2 || ' --Email: ' || v_email2 || 'uco.es');
END;

-- Ejercicio 7
set serveroutput on;
DECLARE
    v_apellido1 votantes.nombreCompleto%type;
    v_apellido2 votantes.nombreCompleto%type;
BEGIN
    SELECT SUBSTR(nombreCompleto, INSTR(nombreCompleto, ' '), 5) INTO v_apellido1 FROM votantes WHERE 
    fechaNacimiento = (SELECT MAX(fechaNacimiento) FROM votantes WHERE fechaNacimiento < (SELECT MAX(fechaNacimiento) FROM votantes));
    SELECT SUBSTR(nombreCompleto, INSTR(nombreCompleto, ' '), 8) INTO v_apellido2 FROM votantes WHERE 
    fechaNacimiento = (SELECT MAX(fechaNacimiento) FROM votantes);
    DBMS_OUTPUT.PUT_LINE('El hijo se llama Juan' || v_apellido1 || v_apellido2);
END;

-- Ejercicio 8
set serveroutput on;
DECLARE
    id1 localidades.idLocalidad%type;
    nHabitantes1 INTEGER:=0;
    nHabitantes2 INTEGER:=0;
    totalHabitantes INTEGER:=0;
    nCiudades INTEGER:=0;
BEGIN
    SELECT idLocalidad, numeroHabitantes INTO id1, nHabitantes1 FROM localidades WHERE idLocalidad = 
    (SELECT MIN(idLocalidad) FROM localidades);
    SELECT numeroHabitantes INTO nHabitantes2 FROM localidades WHERE idLocalidad = id1+1;
    totalHabitantes := nHabitantes1 + nHabitantes2;
    SELECT COUNT(idLocalidad) INTO nCiudades FROM localidades WHERE numeroHabitantes > totalHabitantes;
    DBMS_OUTPUT.PUT_LINE('Hay ' || nCiudades || ' ciudades con mas habitantes de ' || totalHabitantes ||' habitantes, que es la suma de las dos localidades con IDs mas pequeños');
END;