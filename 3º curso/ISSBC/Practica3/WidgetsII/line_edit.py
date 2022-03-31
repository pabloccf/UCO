#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows text which
is entered in a QLineEdit
in a QLabel widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa muestra el texto que ingresamos en el QLineEdit en el widget QLabel.

import sys
from PyQt5.QtWidgets import (QWidget, QLabel,
                             QLineEdit, QApplication)


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.lbl = QLabel(self)
        qle = QLineEdit(self)  #Crea el widget de QLineEdit.

        qle.move(60, 100)
        self.lbl.move(60, 40)

        qle.textChanged[str].connect(self.onChanged)  #Si el texto en el widget de edicion de linea cambia, llamamos al metodo onChanged.


        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('QLineEdit')
        self.show()
        
    #Con este metodo configuramos el texto escrito en el widget de etiqueta.
    def onChanged(self, text):
        self.lbl.setText(text)
        self.lbl.adjustSize()  #Ajusta el tamano de la etiqueta a la longitud del texto.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()