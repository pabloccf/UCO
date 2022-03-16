#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we receive data from
a QInputDialog dialog.

Aauthor: Jan Bodnar
Website: zetcode.com
"""

#En este programa tenemos un boton y un widget de edicion de linea. El boton muestra el cuadro de dialogo de entrada para obtener valores de texto y el texto ingresado se mostrara en el widget de edicion de linea.

from PyQt5.QtWidgets import (QWidget, QPushButton, QLineEdit,
                             QInputDialog, QApplication)
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.btn = QPushButton('Dialog', self)
        self.btn.move(20, 20)
        self.btn.clicked.connect(self.showDialog)

        self.le = QLineEdit(self)
        self.le.move(130, 22)

        self.setGeometry(300, 300, 450, 350)
        self.setWindowTitle('Input dialog')
        self.show()

    def showDialog(self):
        text, ok = QInputDialog.getText(self, 'Input Dialog',
                                        'Enter your name:')  #Muestra el cuadro de dialogo de entrada. La primera cadena es un titulo de dialogo, la segunda es un mensaje dentro del dialogo. El cuadro de dialogo devuelve el texto introducido y un valor booleano. Si hacemos click en el boton Ok, el valor booleano es verdadero.

        if ok:
            self.le.setText(str(text))  #Establece el texto recibido en el widget de edicion de linea.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()