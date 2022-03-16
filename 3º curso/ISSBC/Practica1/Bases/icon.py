#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows an icon
in the titlebar of the window.

Author: Jan Bodnar
Website: zetcode.com
"""

#Aqui importamos los modulos necesarios

import sys  #Este modulo se encarga de suministrar las variables y funcionalidades relacionadas con el interprete.
from PyQt5.QtWidgets import QApplication, QWidget  #En este modulo tenemos los widgets basicos.
from PyQt5.QtGui import QIcon  #Este modulo contiene clases para la integracion de sistemas de ventanas, imagenes basicas, graficos 2D, manejo de eventos, fuentes y texto. La clase QIcon proporciona iconos escalables en diferentes modos y estados.

class Example(QWidget):  #Se define la clase Example con los metodos init y initUI. Ademas la clase Example hereda de la clase QWidget.

    def __init__(self):  #Invoca al metodo init de la superclase, QWidget, para heredar.
        super().__init__()  #Esta funcion nos permite invocar y conservar un metodo de una clase padre desde una clase hija sin tener que nombrarla explicitamente.

        self.initUI()  #Hace referencia a la propia clase e invoca al metodo initUI.


    def initUI(self):  #Invoca al metodo initUI de la superclase, QWidget, para heredar.

        self.setGeometry(300, 300, 300, 220)  #Establece las dimensiones de la ventana.
        self.setWindowTitle('Icon')  #Establece el titulo de la ventana y este se muestra en la barra disponible para ello.
        self.setWindowIcon(QIcon('web.png'))  #Establece un icono a la ventana.

        self.show()  #Este metodo muestra el widget en la pantalla pero primero se crea en la memoria y despues se muestra en la pantalla.


def main():  #Define la funcion principal, funcion main.

    app = QApplication(sys.argv)  #Creamos una instancia de una clase. El parametro sys.argv es una lista de argumentos de una linea de comandos.
    ex = Example()  #Crea una instancia de la clase Example().
    sys.exit(app.exec_())  #Salimos de la clase y el sistema queda a la espera de que se produzca una interrupcion. Ademas este metodo asegura una salida limpia.


if __name__ == '__main__':  #Esta linea de codigo se ejecuta si es el modulo principal pero en el caso de que estuviera importado no se ejecutaria.
    main()  #Invoca a la funcion main.