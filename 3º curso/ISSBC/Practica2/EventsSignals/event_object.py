#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we display the x and y
coordinates of a mouse pointer in a label widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa se encarga de mostrar las coordenadas "x" e "y" del puntero del raton en un widget de etiqueta.

import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QApplication, QGridLayout, QLabel


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        grid = QGridLayout()

        x = 0
        y = 0

        self.text = f'x: {x},  y: {y}'

        self.label = QLabel(self.text, self)  #Muestra en el widget QLabel las coordenadas "x" e "y".
        grid.addWidget(self.label, 0, 0, Qt.AlignTop)

        self.setMouseTracking(True)  #Al estar activado el seguimiento del raton recibe eventos de movimiento siempre, aunque no se este pulsando ningun boton.

        self.setLayout(grid)

        self.setGeometry(300, 300, 450, 300)
        self.setWindowTitle('Event object')
        self.show()

    def mouseMoveEvent(self, e):
        x = e.x()  #Determina la coordenada "x" del puntero del raton. 
        y = e.y()  #Determina la coordenada "y" del puntero del raton.

        text = f'x: {x},  y: {y}'  #Crea la cadena.
        self.label.setText(text)  #Configura la cadena en el widget de etiqueta.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()