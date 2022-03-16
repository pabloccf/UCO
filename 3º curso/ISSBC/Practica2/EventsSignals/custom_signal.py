#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we show how to
emit a custom signal.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa crea una nueva senal llamada closeApp. Esta senal se emite durante un evento de presion del raton.

import sys
from PyQt5.QtCore import pyqtSignal, QObject
from PyQt5.QtWidgets import QMainWindow, QApplication


class Communicate(QObject):

    closeApp = pyqtSignal()  #Crea una senal como un atributo de clase de la clase externa Communicate.


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.c = Communicate()
        self.c.closeApp.connect(self.close)  #Conecta la senal personalizada closeApp a la ranura de cierre de QMainWindow.

        self.setGeometry(300, 300, 450, 350)
        self.setWindowTitle('Emit signal')
        self.show()

    def mousePressEvent(self, event):

        self.c.closeApp.emit()  #Cuando hacemos click en la ventana con el puntero del raton se emite la senal de cierre.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()