#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example draws three rectangles in three
different colours.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa dibuja tres rectangulos en tres diferentes colores.

from PyQt5.QtWidgets import QWidget, QApplication
from PyQt5.QtGui import QPainter, QColor, QBrush
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setGeometry(300, 300, 350, 100)
        self.setWindowTitle('Colours')
        self.show()

    def paintEvent(self, e):
        qp = QPainter()
        qp.begin(self)
        self.drawRectangles(qp)
        qp.end()

    def drawRectangles(self, qp):
        #Definimos un color usando una notacion hexadecimal.
        col = QColor(0, 0, 0)
        col.setNamedColor('#d4d4d4')
        qp.setPen(col)

        qp.setBrush(QColor(200, 0, 0))  #Define un pincel.
        qp.drawRect(10, 15, 90, 60)  #Dibuja un rectangulo. El metodo drawRect acepta cuatro parametros: los dos primeros son valores x e y en el eje, los parametros tercero y cuarto son el ancho y el alto del rectangulo. El metodo dibuja el rectangulo usando la pluma y el pincel actuales.

        qp.setBrush(QColor(255, 80, 0, 160))
        qp.drawRect(130, 15, 90, 60)

        qp.setBrush(QColor(25, 0, 90, 200))
        qp.drawRect(250, 15, 90, 60)


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()