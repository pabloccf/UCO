#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows how to use
a QComboBox widget.

Author: Jan Bodnar
Website: zetcode.com
"""

import sys

from PyQt5.QtWidgets import (QWidget, QLabel,
                             QComboBox, QApplication)


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.lbl = QLabel('Ubuntu', self)
        
        #Creamos un widget QComboBox con las cinco opciones.
        combo = QComboBox(self)  #Crea un widget QComboBox.
        combo.addItem('Ubuntu')  #Anade una opción al widget.
        combo.addItem('Mandriva')
        combo.addItem('Fedora')
        combo.addItem('Arch')
        combo.addItem('Gentoo')

        combo.move(50, 50)
        self.lbl.move(50, 150)

        combo.activated[str].connect(self.onActivated)  #Tras la seleccion de un elemento, llamamos al metodo onActivated.

        self.setGeometry(300, 300, 450, 400)
        self.setWindowTitle('QComboBox')
        self.show()
        
    #En este metodo configuramos el texto de la opcion elegida en el widget de etiqueta.
    def onActivated(self, text):
        self.lbl.setText(text)
        self.lbl.adjustSize()  #Ajusta el tamano de la etiqueta.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()