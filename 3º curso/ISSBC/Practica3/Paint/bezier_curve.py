#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program draws a Bézier curve with
QPainterPath.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa dibuja una curva bezier con QPainterPath.

import sys

from PyQt5.QtGui import QPainter, QPainterPath
from PyQt5.QtWidgets import QWidget, QApplication


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setGeometry(300, 300, 380, 250)
        self.setWindowTitle('Bézier curve')
        self.show()

    def paintEvent(self, e):
        qp = QPainter()
        qp.begin(self)
        qp.setRenderHint(QPainter.Antialiasing)
        self.drawBezierCurve(qp)
        qp.end()

    def drawBezierCurve(self, qp):
        path = QPainterPath()  #Crea una curva Bezier con la ruta QPainterPath.
        path.moveTo(30, 30)
        path.cubicTo(30, 30, 200, 350, 350, 30)  #Crea la curva que toma tres puntos: punto inicial, punto de control y punto final.

        qp.drawPath(path)  #Dibuja la ruta final.


def main():

    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()