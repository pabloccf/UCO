#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows a QSlider widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa simula un control de volumen en el que al arrastrar el controlador de un control deslizante cambiamos la imagen de la etiqueta.

from PyQt5.QtWidgets import (QWidget, QSlider,
                             QLabel, QApplication)
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPixmap
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        sld = QSlider(Qt.Horizontal, self)  #Crea un QSlider horizontal.
        sld.setFocusPolicy(Qt.NoFocus)
        sld.setGeometry(30, 40, 200, 30)
        sld.valueChanged[int].connect(self.changeValue)  #Conecta la senal valueChanged al metodo changeValue definido por el usuario.

        self.label = QLabel(self)  #Crea un widget QLabel.
        self.label.setPixmap(QPixmap('mute.png'))  #Configura una imagen inicial, mute.png.
        self.label.setGeometry(250, 40, 80, 30)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('QSlider')
        self.show()

    def changeValue(self, value):  #Dependiendo del valor del control deslizante establece una imagen u otra en la etiqueta.

        if value == 0:  #Si el control deslizante es igual a cero.

            self.label.setPixmap(QPixmap('mute.png'))  #Configura la imagen mute.png en la etiqueta.
        elif 0 < value <= 30:

            self.label.setPixmap(QPixmap('min.png'))
        elif 30 < value < 80:

            self.label.setPixmap(QPixmap('med.png'))
        else:

            self.label.setPixmap(QPixmap('max.png'))


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()