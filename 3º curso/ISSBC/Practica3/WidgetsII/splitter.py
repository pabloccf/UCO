#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows
how to use QSplitter widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa muestra tres widgets de QFrame organizados con dos divisores.

import sys

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QHBoxLayout, QFrame,
                             QSplitter, QApplication)


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        hbox = QHBoxLayout(self)

        topleft = QFrame(self)  #Crea un widget de marco.
        topleft.setFrameShape(QFrame.StyledPanel)  #Usamos un marco con estilo para ver los limites entre los widgets de QFrame.

        topright = QFrame(self)
        topright.setFrameShape(QFrame.StyledPanel)

        bottom = QFrame(self)
        bottom.setFrameShape(QFrame.StyledPanel)
        
        splitter1 = QSplitter(Qt.Horizontal)  #Crea un widget QSplitter.
        splitter1.addWidget(topleft)  #Anade un marco al widget QSplitter.
        splitter1.addWidget(topright)
        
        #Anadimos un splitter a otro widget splitter.
        splitter2 = QSplitter(Qt.Vertical)
        splitter2.addWidget(splitter1)  #Anade un widget QSplitter a otro widget QSplitter.
        splitter2.addWidget(bottom)

        hbox.addWidget(splitter2)
        self.setLayout(hbox)

        self.setGeometry(300, 300, 450, 400)
        self.setWindowTitle('QSplitter')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()