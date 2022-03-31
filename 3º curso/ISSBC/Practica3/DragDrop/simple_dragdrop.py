#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This is a simple drag and
drop example.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa ejecuta una simple operacion de arrastrar y soltar.

import sys

from PyQt5.QtWidgets import (QPushButton, QWidget,
                             QLineEdit, QApplication)

#Con el objetivo de soltar texto en el widget QPushButton, debemos reimplementar algunos metodos. Por lo tanto, creamos nuestra propia clase Button, que heredara de la clase QPushButton.
class Button(QPushButton):

    def __init__(self, title, parent):
        super().__init__(title, parent)

        self.setAcceptDrops(True)  #Habilita eventos de caida para el widget con setAcceptDrops.

    #Primero reimplementamos el metodo dragEnterEvent. Informamos del tipo de dato que se acepta. En este caso es texto plano.
    def dragEnterEvent(self, e):

        if e.mimeData().hasFormat('text/plain'):
            e.accept()
        else:
            e.ignore()

    #Reimplementando el metodo dropEvent, definimos que pasa en el evento de caida. Aqui cambiamos el texto del boton.
    def dropEvent(self, e):

        self.setText(e.mimeData().text())


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        edit = QLineEdit('', self)  #El widget QLineEdit tiene un soporte incorporado para operaciones de arrastre.
        edit.setDragEnabled(True)  #Activa el soporte incorporado al widget QLineEdit para operaciones de arrastre.
        edit.move(30, 65)

        button = Button("Button", self)
        button.move(190, 65)

        self.setWindowTitle('Simple drag and drop')
        self.setGeometry(300, 300, 300, 150)


def main():

    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    app.exec_()


if __name__ == '__main__':
    main()