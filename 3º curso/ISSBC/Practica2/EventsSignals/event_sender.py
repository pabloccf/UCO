#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we determine the event sender
object.

Author: Jan Bodnar
Website: zetcode.com
"""

#En este programa tenemos dos botones y con el metodo buttonClicked determinamos en que boton hemos hecho click llamando al metodo del remitente. 

import sys
from PyQt5.QtWidgets import QMainWindow, QPushButton, QApplication


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        btn1 = QPushButton("Button 1", self)
        btn1.move(30, 50)

        btn2 = QPushButton("Button 2", self)
        btn2.move(150, 50)

        #Ambos botones estan conectados a la misma ranura.
        btn1.clicked.connect(self.buttonClicked)
        btn2.clicked.connect(self.buttonClicked)

        self.statusBar()

        self.setGeometry(300, 300, 450, 350)
        self.setWindowTitle('Event sender')
        self.show()

    def buttonClicked(self):
        sender = self.sender()  #Determinamos la fuente de la senal.
        self.statusBar().showMessage(sender.text() + ' was pressed')  #Muestra en la barra de estado de la aplicacion la etiqueta del boton que se esta presionando.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()