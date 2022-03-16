#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we select a color value
from the QColorDialog and change the background
color of a QFrame widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa muestra un boton pulsador y un QFrame. El fondo del widget esta configurado en color negro y usando QColorDialog, podemos cambiar su fondo.

from PyQt5.QtWidgets import (QWidget, QPushButton, QFrame,
                             QColorDialog, QApplication)
from PyQt5.QtGui import QColor
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        col = QColor(0, 0, 0)  #Es un color inicial del fondo de QFrame.

        self.btn = QPushButton('Dialog', self)
        self.btn.move(20, 20)

        self.btn.clicked.connect(self.showDialog)

        self.frm = QFrame(self)
        self.frm.setStyleSheet("QWidget { background-color: %s }"
                               % col.name())
        self.frm.setGeometry(130, 22, 200, 200)

        self.setGeometry(300, 300, 450, 350)
        self.setWindowTitle('Color dialog')
        self.show()

    def showDialog(self):
        col = QColorDialog.getColor()  #Hace que aparezca el QColorDialog.

        if col.isValid():  #Comprobamos si el color es valido. Si hacemos click en el boton Cancelar, no se devuelve ningun color valido. Si el color es valido, cambiamos el color de fondo usando hojas de estilo.
            self.frm.setStyleSheet('QWidget { background-color: %s }'
                                   % col.name())


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()