#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In the example, we draw randomly 1000 red points
on the window.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa dibujamos al azar 1000 puntos rojos en la ventana.

from PyQt5.QtWidgets import QWidget, QApplication
from PyQt5.QtGui import QPainter
from PyQt5.QtCore import Qt
import sys, random


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setGeometry(300, 300, 300, 190)
        self.setWindowTitle('Points')
        self.show()

    def paintEvent(self, e):
        qp = QPainter()
        qp.begin(self)
        self.drawPoints(qp)
        qp.end()

    def drawPoints(self, qp):
        qp.setPen(Qt.red)  #Pone el boligrafo en color rojo. Usamos una constante de color Qt.red predefinida.
        size = self.size()  #Cada vez que cambiamos el tamano de la ventana, se genera un evento de pintura. Obtenemos el tamano actual de la ventana con el metodo de tamano. Usamos el tamano de la ventana para distribuir los puntos por toda el area del cliente de la ventana.

        if size.height() <= 1 or size.height() <= 1:
            return

        for i in range(1000):
            x = random.randint(1, size.width() - 1)
            y = random.randint(1, size.height() - 1)
            qp.drawPoint(x, y)  #Dibuja el punto.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()