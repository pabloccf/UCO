#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows three labels on a window
using absolute positioning.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa muestra tres etiquetas en una ventana usando el posicionamiento absoluto.

import sys
from PyQt5.QtWidgets import QWidget, QLabel, QApplication  #QLabel proporciona una visualizacion de texto o imagen.

class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        lbl1 = QLabel('ZetCode', self)  #Muestra texto o imagenes no editables y tambien puede colocar una animacion GIF u otros controles.
        lbl1.move(15, 10)  #Mueve la etiqueta en la direccion x e y.

        lbl2 = QLabel('tutorials', self)
        lbl2.move(35, 40)

        lbl3 = QLabel('for programmers', self)
        lbl3.move(55, 70)

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Absolute')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()