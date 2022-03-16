#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows a QProgressBar widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa tiene una barra de progreso horizontal y un pulsador. El pulsador inicia y detiene la barra de progreso.

from PyQt5.QtWidgets import (QWidget, QProgressBar,
                             QPushButton, QApplication)
from PyQt5.QtCore import QBasicTimer
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.pbar = QProgressBar(self)  #Es el constructor del QProgressBar.
        self.pbar.setGeometry(30, 40, 200, 25)

        self.btn = QPushButton('Start', self)
        self.btn.move(40, 80)
        self.btn.clicked.connect(self.doAction)

        self.timer = QBasicTimer()  #Para activar la barra de progreso, usamos un objeto de temporizador.
        self.step = 0

        self.setGeometry(300, 300, 280, 170)
        self.setWindowTitle('QProgressBar')
        self.show()

    def timerEvent(self, e):  #Es un controlador de eventos.

        if self.step >= 100:
            self.timer.stop()
            self.btn.setText('Finished')
            return

        self.step = self.step + 1
        self.pbar.setValue(self.step)

    def doAction(self):  #Dentro de este metodo iniciamos y detenemos el temporizador.

        if self.timer.isActive():
            self.timer.stop()
            self.btn.setText('Start')
        else:
            self.timer.start(100, self)  #Para iniciar un evento de temporizador, llamamos a su metodo de inicio. Este metodo tiene dos parametros: el tiempo de espera y el objeto que recibira los eventos.
            self.btn.setText('Stop')


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
