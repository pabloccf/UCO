#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program creates a toolbar.
The toolbar has one action, which
terminates the application, if triggered.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa crea una barra de herramientas en la que esta tiene una opcion de terminar la aplicacion.

import sys
from PyQt5.QtWidgets import QMainWindow, QAction, qApp, QApplication
from PyQt5.QtGui import QIcon


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        exitAct = QAction(QIcon('exit24.png'), 'Exit', self)  #Crea una accion con un icono especifico y una etiqueta de salir.
        exitAct.setShortcut('Ctrl+Q')  #Crea un atajo para realizar la accion especificada, en este caso Salir.
        exitAct.triggered.connect(qApp.quit)  #Emite una senal disparada que en este caso esta conectada al metodo de salida del widget QApplication.

        self.toolbar = self.addToolBar('Exit')  #Crea una barra de herramientas.
        self.toolbar.addAction(exitAct)  #Agrega un objeto de accion a la barra de herramientas.

        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Toolbar')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()