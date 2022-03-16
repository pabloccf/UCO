#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows a tooltip on
a window and a button.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este codigo muestra una ventana emergente con un boton que al mantener el raton encima de el nos sale un texto.

import sys  #Este modulo se encarga de suministrar las variables y funcionalidades relacionadas con el interprete.
from PyQt5.QtWidgets import (QWidget, QToolTip,
    QPushButton, QApplication)  #En este modulo tenemos los widgets basicos.
from PyQt5.QtGui import QFont  #Este modulo contiene clases para la integracion de sistemas de ventanas, imagenes basicas, graficos 2D, manejo de eventos, fuentes y texto.


class Example(QWidget):  #Se define la clase Example con los metodos init y initUI. Ademas la clase Example hereda de la clase QWidget.

    def __init__(self):  #Invoca al metodo init de la superclase, QWidget, para heredar.
        super().__init__()  #Esta funcion nos permite invocar y conservar un metodo de una clase padre desde una clase hija sin tener que nombrarla explicitamente.

        self.initUI()  #Hace referencia a la propia clase e invoca al metodo initUI.


    def initUI(self):  #Invoca al metodo initUI de la superclase, QWidget, para heredar.

        QToolTip.setFont(QFont('SansSerif', 10))  #Establece una fuente utilizada para representar informacion sobre herramientas.

        self.setToolTip('This is a <b>QWidget</b> widget')  #Crea informacion sobre las herramientas.

        btn = QPushButton('Button', self)  #Crea un widget de boton pulsador.
        btn.setToolTip('This is a <b>QPushButton</b> widget')  #Configuramos informacion sobre herramientas para el boton pulsador.
        btn.resize(btn.sizeHint())  #En este caso redimensiona el boton. El metodo sizeHint() proporciona un tamaño recomendado para el boton.
        btn.move(50, 50)  #Mueve el boton en la ventana.

        self.setGeometry(300, 300, 300, 200)  #Establece las dimensiones de la ventana.
        self.setWindowTitle('Tooltips')  #Establece el titulo de la ventana y este se muestra en la barra disponible para ello.
        self.show()  #Este metodo muestra el widget en la pantalla pero primero se crea en la memoria y despues se muestra en la pantalla.


def main():  #Define la funcion principal, funcion main.

    app = QApplication(sys.argv)  #Creamos una instancia de una clase. El parametro sys.argv es una lista de argumentos de una linea de comandos.
    ex = Example()  #Crea una instancia de la clase Example().
    sys.exit(app.exec_())  #Salimos de la clase y el sistema queda a la espera de que se produzca una interrupcion. Ademas este metodo asegura una salida limpia.


if __name__ == '__main__':  #Esta linea de codigo se ejecuta si es el modulo principal pero en el caso de que estuviera importado no se ejecutaria.
    main()  #Invoca a la funcion main.