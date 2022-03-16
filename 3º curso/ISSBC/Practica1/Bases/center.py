#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program centers a window
on the screen.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este codigo centra una ventana emergente en el centro de la pantalla.

import sys  #Este modulo se encarga de suministrar las variables y funcionalidades relacionadas con el interprete.
from PyQt5.QtWidgets import QWidget, QDesktopWidget, QApplication  #En este modulo tenemos los widgets basicos.


class Example(QWidget):  #Se define la clase Example con los metodos init y initUI. Ademas la clase Example hereda de la clase QWidget.

    def __init__(self):  #Invoca al metodo init de la superclase, QWidget, para heredar.
        super().__init__()  #Esta funcion nos permite invocar y conservar un metodo de una clase padre desde una clase hija sin tener que nombrarla explicitamente.

        self.initUI()  #Hace referencia a la propia clase e invoca al metodo initUI.

    def initUI(self):  #Invoca al metodo initUI de la superclase, QWidget, para heredar.

        self.resize(250, 150)  #En este caso redimensiona la ventana emergente.
        self.center()  #Centra la ventana emergente.

        self.setWindowTitle('Center')  #Establece el titulo de la ventana y este se muestra en la barra disponible para ello.
        self.show()  #Este metodo muestra el widget en la pantalla pero primero se crea en la memoria y despues se muestra en la pantalla.

    def center(self):  #Invoca al metodo center de la superclase, QWidget, para heredar.

        qr = self.frameGeometry()  #Establece la geometria de la ventana.
        cp = QDesktopWidget().availableGeometry().center()  #Calculamos la resolucion de la pantalla del monitor y asi obtenemos el punto central.
        qr.moveCenter(cp)  #Centra el centro de la ventana en el centro de la pantalla. El tamano no cambia.
        self.move(qr.topLeft())  #Movemos el punto superior izquierdo de la ventana de aplicacion al punto superior izquierdo del rectangulo qr, centrando asi la ventana en nuestra pantalla.


def main():  #Define la funcion principal, funcion main.

    app = QApplication(sys.argv)  #Creamos una instancia de una clase. El parametro sys.argv es una lista de argumentos de una linea de comandos.
    ex = Example()  #Crea una instancia de la clase Example().
    sys.exit(app.exec_())  #Salimos de la clase y el sistema queda a la espera de que se produzca una interrupcion. Ademas este metodo asegura una salida limpia.


if __name__ == '__main__':  #Esta linea de codigo se ejecuta si es el modulo principal pero en el caso de que estuviera importado no se ejecutaria.
    main()  #Invoca a la funcion main.