-- Ejercicio 3.1
DROP TABLE JOVENES;
CREATE TABLE JOVENES(
    dni NUMBER(8) PRIMARY KEY,
    nombre VARCHAR2(64),
    apellidos VARCHAR2(64),
    sueldo NUMBER(5),
    fechaNacimiento DATE,
    email VARCHAR2(32));