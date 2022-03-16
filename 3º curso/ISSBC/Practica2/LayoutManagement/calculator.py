#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we create a skeleton
of a calculator using QGridLayout.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa crea un esqueleto de una calculadora.

import sys
from PyQt5.QtWidgets import (QWidget, QGridLayout,
                             QPushButton, QApplication)


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        grid = QGridLayout()  #Divide la ventana en una cuadricula de filas y columnas para organizarla.
        self.setLayout(grid)  #Establece el diseno principal de la ventana.

        names = ['Cls', 'Bck', '', 'Close',
                 '7', '8', '9', '/',
                 '4', '5', '6', '*',
                 '1', '2', '3', '-',
                 '0', '.', '=', '+']  #Estas son las etiquetas que se usaran despues para los botones.

        positions = [(i, j) for i in range(5) for j in range(4)]  #Crea una lista de posiciones en la cuadricula.

        for position, name in zip(positions, names):

            if name == '':
                continue
            button = QPushButton(name)
            grid.addWidget(button, *position)  #Crea y agrega los botones al diseno.

        self.move(300, 150)
        self.setWindowTitle('Calculator')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()