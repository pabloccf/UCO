#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we position two push
buttons in the bottom-right corner
of the window.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa ejecuta una ventana que tiene dos botones en la esquina inferior derecha.

import sys
from PyQt5.QtWidgets import (QWidget, QPushButton,
                             QHBoxLayout, QVBoxLayout, QApplication)


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        okButton = QPushButton("OK")  #Crea un widget de boton pulsador.
        cancelButton = QPushButton("Cancel")

        hbox = QHBoxLayout()  #Crea un diseno de cuadro horizontal.
        hbox.addStretch(1)  #Agrega un factor de estiramiento.
        hbox.addWidget(okButton)  #Agrega el boton de OK al cuadro horizontal creado anteriormente.
        hbox.addWidget(cancelButton)  #Agrega el boton de Cancel al cuadro horizontal creado anteriormente.

        vbox = QVBoxLayout()  #Crea un diseno de cuadro vertical, colocando el cuadro horizontal en este.
        vbox.addStretch(1)  #Agrega un factor de estiramiento.
        vbox.addLayout(hbox)  #Agrega el diseno de cuadro horizontal al vertical.

        self.setLayout(vbox)  #Establece el diseno principal de la ventana.

        self.setGeometry(300, 300, 300, 150)
        self.setWindowTitle('Buttons')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()