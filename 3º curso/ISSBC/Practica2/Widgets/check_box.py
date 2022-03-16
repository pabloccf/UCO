#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, a QCheckBox widget
is used to toggle the title of a window.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa crea una casilla de verificacion que alternara el titulo de la ventana.

from PyQt5.QtWidgets import QWidget, QCheckBox, QApplication
from PyQt5.QtCore import Qt
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        cb = QCheckBox('Show title', self)  #Constructor de QCheckBox.
        cb.move(20, 20)
        cb.toggle()  #Marca la casilla de verificacion.
        cb.stateChanged.connect(self.changeTitle)  #Conectamos el metodo changeTitle definido por el usuario a la senal stateChanged. El metodo changeTitle cambiara el titulo de la ventana.

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('QCheckBox')
        self.show()

    def changeTitle(self, state):

        if state == Qt.Checked:  #Si el widget esta marcado, establecemos un titulo de la ventana.
            self.setWindowTitle('QCheckBox')
        else:  #De lo contrario, establecemos una cadena vacia en la barra de titulo.
            self.setWindowTitle(' ')


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()