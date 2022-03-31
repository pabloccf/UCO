#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we create a custom widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa crea un widget personalizado.

from PyQt5.QtWidgets import (QWidget, QSlider, QApplication,
                             QHBoxLayout, QVBoxLayout)
from PyQt5.QtCore import QObject, Qt, pyqtSignal
from PyQt5.QtGui import QPainter, QFont, QColor, QPen
import sys


class Communicate(QObject):
    updateBW = pyqtSignal(int)

#El widget de grabacion se basa en el widget QWidget.
class BurningWidget(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.setMinimumSize(1, 30)  #Cambia la altura minima del widget. El valor predeterminado es pequeno.
        self.value = 75
        self.num = [75, 150, 225, 300, 375, 450, 525, 600, 675]

    def setValue(self, value):

        self.value = value

    def paintEvent(self, e):

        qp = QPainter()
        qp.begin(self)
        self.drawWidget(qp)
        qp.end()

    def drawWidget(self, qp):

        MAX_CAPACITY = 700
        OVER_CAPACITY = 750
        
        #Usamos una fuente mas pequena que la predeterminada. Esto se adapta mejor a nuestras necesidades.
        font = QFont('Serif', 7, QFont.Light)
        qp.setFont(font)
        
        #Dibujamos el widget dinamicamente. Cuanto mayor es la ventana, mayor es el widget de grabacion y viceversa. Por eso debemos calcular el tamano del widget sobre el que dibujaremos el widget personalizado. 
        #El parametro de caja determina el tamano total a dibujar. Este valor proviene del control deslizante. Es una proporcion de toda el area. El parametro full determina el punto donde comenzamos a dibujar en color rojo.
        #El dibujo real consta de tres pasos. Dibujamos el rectangulo amarillo o rojo y amarillo. Luego dibujamos las lineas verticales que dividen el widget en varias partes. Finalmente, dibujamos los numeros que indican la capacidad del medio.
        size = self.size()
        w = size.width()
        h = size.height()

        step = int(round(w / 10))

        till = int(((w / OVER_CAPACITY) * self.value))
        full = int(((w / OVER_CAPACITY) * MAX_CAPACITY))

        if self.value >= MAX_CAPACITY:

            qp.setPen(QColor(255, 255, 255))
            qp.setBrush(QColor(255, 255, 184))
            qp.drawRect(0, 0, full, h)
            qp.setPen(QColor(255, 175, 175))
            qp.setBrush(QColor(255, 175, 175))
            qp.drawRect(full, 0, till - full, h)

        else:

            qp.setPen(QColor(255, 255, 255))
            qp.setBrush(QColor(255, 255, 184))
            qp.drawRect(0, 0, till, h)

        pen = QPen(QColor(20, 20, 20), 1,
                   Qt.SolidLine)

        qp.setPen(pen)
        qp.setBrush(Qt.NoBrush)
        qp.drawRect(0, 0, w - 1, h - 1)

        j = 0

        for i in range(step, 10 * step, step):

            qp.drawLine(i, 0, i, 5)
            #Usamos metricas de fuente para dibujar el texto. Debemos conocer el ancho del texto para poder centrarlo alrededor de la linea vertical.
            metrics = qp.fontMetrics()
            fw = metrics.width(str(self.num[j]))

            x, y = int(i - fw/2), int(h / 2)
            qp.drawText(x, y, str(self.num[j]))
            j = j + 1


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        OVER_CAPACITY = 750

        sld = QSlider(Qt.Horizontal, self)
        sld.setFocusPolicy(Qt.NoFocus)
        sld.setRange(1, OVER_CAPACITY)
        sld.setValue(75)
        sld.setGeometry(30, 40, 150, 30)

        self.c = Communicate()
        self.wid = BurningWidget()
        self.c.updateBW[int].connect(self.wid.setValue)

        sld.valueChanged[int].connect(self.changeValue)
        hbox = QHBoxLayout()
        hbox.addWidget(self.wid)
        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addLayout(hbox)
        self.setLayout(vbox)

        self.setGeometry(300, 300, 390, 210)
        self.setWindowTitle('Burning widget')
        self.show()
    
    #Cuando movemos el control deslizante se llama a este metodo.
    def changeValue(self, value):
        self.c.updateBW.emit(value)  #Envia una senal updateBW con un parametro. El parametro es el valor actual del control deslizante. El valor se utiliza posteriormente para calcular la capacidad del widget de grabacion que se va a dibujar.
        self.wid.repaint()  #Vuelve a pintar el widget personalizado.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()