#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program creates a menubar. The
menubar has one menu with an exit action.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa ejecuta una barra de menu y este tiene un menu con una accion de salir.

import sys
from PyQt5.QtWidgets import QMainWindow, QAction, qApp, QApplication
from PyQt5.QtGui import QIcon


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        exitAct = QAction(QIcon('exit.png'), '&Exit', self)  #Crea una accion con un icono especifico y una etiqueta de salir.
        exitAct.setShortcut('Ctrl+Q')  #Crea un atajo para realizar la accion especificada, en este caso Salir.
        exitAct.setStatusTip('Exit application')  #Crea una sugerencia de estado que se muestra en la barra de estado cuando pasamos el raton por encima del elemento del menu.
        exitAct.triggered.connect(qApp.quit)  #Emite una senal disparada que en este caso esta conectada al metodo de salida del widget QApplication.

        self.statusBar()

        menubar = self.menuBar()  #Crea una barra de menu.
        fileMenu = menubar.addMenu('&File')  #Creamos un menu de archivo
        fileMenu.addAction(exitAct)  #Agregamos la accion al menu.

        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Simple menu')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()