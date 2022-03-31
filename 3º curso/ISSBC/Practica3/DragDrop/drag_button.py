#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this program, we can press on a button with a left mouse
click or drag and drop the button with  the right mouse click.

Author: Jan Bodnar
Website: zetcode.com
"""

#En este programa podemos presionar un boton con el boton izquierdo del raton, click o arrastre y suelte el boton con el boton derecho del raton.

import sys

from PyQt5.QtCore import Qt, QMimeData
from PyQt5.QtGui import QDrag
from PyQt5.QtWidgets import QPushButton, QWidget, QApplication


#Creamos una clase Button que hereda de QPushButton. Reimplementamos dos metodos de QPushButton: mouseMoveEvent y mousePressEvent.
class Button(QPushButton):

    def __init__(self, title, parent):
        super().__init__(title, parent)
    
    #Este metodo es el lugar donde comienza la operacion de arrastrar y soltar.
    def mouseMoveEvent(self, e):
        
        #Solo podemos arrastrar y soltar con el boton derecho del raton. El izquierdo es solo para hacer click en el boton.
        if e.buttons() != Qt.RightButton:
            return
        
        #Se crea el objeto QDrag. La clase proporciona soporte para la transferencia de datos de arrastrar y soltar basada en MIME.
        mimeData = QMimeData()

        drag = QDrag(self)
        drag.setMimeData(mimeData)
        drag.setHotSpot(e.pos() - self.rect().topLeft())


        dropAction = drag.exec_(Qt.MoveAction)  #El metodo exec_ del objeto drag empieza la operacion de arrastrar y soltar.


    #Imprimimos 'press' en la consola si clickamos en el boton izquierdo del raton. Hay que tener en cuenta que tambien llamamos a mousePressEvent en el padre. De lo contrario, no veriamos que se pulsa el boton.
    def mousePressEvent(self, e):

        super().mousePressEvent(e)

        if e.button() == Qt.LeftButton:
            print('press')


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.setAcceptDrops(True)

        self.button = Button('Button', self)
        self.button.move(100, 65)

        self.setWindowTitle('Click or Move')
        self.setGeometry(300, 300, 550, 450)

    def dragEnterEvent(self, e):
        e.accept()

    def dropEvent(self, e):
        #Especificamos que pasa despues de que soltemos el boton del raton y terminemos la operacion de soltar.
        position = e.pos()  #Averigua la posicion actual del puntero del raton.
        self.button.move(position)  #Mueve el boton en consecuencia de la posicion del puntero del raton.

        e.setDropAction(Qt.MoveAction)  #Especifica el tipo de accion de soltar. En este caso es una accion de movimiento.

        e.accept()


def main():
    
    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    app.exec_()


if __name__ == '__main__':
    main()