#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we draw text in Russian Cylliric.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa dibuja texto en cirilico ruso.

import sys
from PyQt5.QtWidgets import QWidget, QApplication
from PyQt5.QtGui import QPainter, QColor, QFont
from PyQt5.QtCore import Qt


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.text = "Лев Николаевич Толстой\nАнна Каренина"

        self.setGeometry(300, 300, 350, 300)
        self.setWindowTitle('Drawing text')
        self.show()

    #Aqui se realiza el dibujo.
    def paintEvent(self, event):
        #La clase QPainter es responsable de toda la pintura de bajo nivel. Todos los metodos de pintura van entre los metodos de inicio y finalizacion. La pintura real se delega al metodo drawText.
        qp = QPainter()
        qp.begin(self)
        self.drawText(event, qp)
        qp.end()

    def drawText(self, event, qp):
        qp.setPen(QColor(168, 34, 3))  #Definimos un boligrafo para dibujar el texto.
        qp.setFont(QFont('Decorative', 10))  #Definimos una fuente que se utiliza para dibujar texto.
        qp.drawText(event.rect(), Qt.AlignCenter, self.text)  #El metodo drawText dibuja texto en la ventana. El metodo rect del evento paint devuelve el rectangulo que debe actualizarse. Con el Qt.AlignCenter alineamos el texto en ambas dimensiones.


def main():

    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()