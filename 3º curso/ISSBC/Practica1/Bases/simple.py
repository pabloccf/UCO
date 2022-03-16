#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we create a simple
window in PyQt5.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este codigo muestra una pequena ventana emergente.

import sys  #Este modulo se encarga de suministrar las variables y funcionalidades relacionadas con el interprete.
from PyQt5.QtWidgets import QApplication, QWidget  #En este modulo tenemos los widgets basicos.


def main():  #Define la funcion principal, funcion main.

    app = QApplication(sys.argv)  #Creamos una instancia de una clase. El parametro sys.argv es una lista de argumentos de una linea de comandos.

    w = QWidget()  #Creamos el constructor predeterminado para QWidget, que al no tener padre este widget, por lo tanto se le llama ventana.
    w.resize(250, 150)  #Cambia el tamano de la ventana poniendole 250 px de ancho y 150 px de alto.
    w.move(300, 300)  #Mueve la ventana a la posicion de la pantalla con coordenadas x=300, y=300.
    w.setWindowTitle('Simple')  #Establece el titulo de la ventana y este se muestra en la barra disponible para ello.
    w.show()  #Este metodo muestra el widget en la pantalla pero primero se crea en la memoria y despues se muestra en la pantalla.

    sys.exit(app.exec_())  #Salimos de la clase y el sistema queda a la espera de que se produzca una interrupcion. Ademas este metodo asegura una salida limpia.


if __name__ == '__main__':  #Esta linea de codigo se ejecuta si es el modulo principal pero en el caso de que estuviera importado no se ejecutaria.
    main()  #Invoca a la funcion main.