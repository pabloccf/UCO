#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example we draw 6 lines using
different pen styles.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa dibuja 6 lineas usando diferentes estilos de pluma.

from PyQt5.QtWidgets import QWidget, QApplication
from PyQt5.QtGui import QPainter, QPen
from PyQt5.QtCore import Qt
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setGeometry(300, 300, 280, 270)
        self.setWindowTitle('Pen styles')
        self.show()

    def paintEvent(self, e):
        qp = QPainter()
        qp.begin(self)
        self.drawLines(qp)
        qp.end()

    def drawLines(self, qp):
        pen = QPen(Qt.black, 2, Qt.SolidLine)  #Crea un objeto QPen. El color es negro. El ancho se establece en 2 pixeles para que podamos ver las diferencias entre los estilos de lapiz. Qt.SolidLine es uno de los estilos de pluma predefinidos.

        qp.setPen(pen)
        qp.drawLine(20, 40, 250, 40)

        pen.setStyle(Qt.DashLine)
        qp.setPen(pen)
        qp.drawLine(20, 80, 250, 80)

        pen.setStyle(Qt.DashDotLine)
        qp.setPen(pen)
        qp.drawLine(20, 120, 250, 120)

        pen.setStyle(Qt.DotLine)
        qp.setPen(pen)
        qp.drawLine(20, 160, 250, 160)

        pen.setStyle(Qt.DashDotDotLine)
        qp.setPen(pen)
        qp.drawLine(20, 200, 250, 200)

        pen.setStyle(Qt.CustomDashLine)  #Define y establece un estilo de pluma personalizado.
        pen.setDashPattern([1, 4, 5, 4])  #La lista de numeros define un estilo. Debe haber un numero par de numeros. Los numeros impares definen un espacio de guion, numeros pares. Cuanto mayor sea el numero, mayor sera el espacio o el guion. Nuestro patron es un guion de 1 px, un espacio de 4 px, un guion de 5 px, un espacio de 4 px, etc.
        qp.setPen(pen)
        qp.drawLine(20, 240, 250, 240)


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()