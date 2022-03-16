#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program creates a statusbar.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa ejecuta una barra de estado

import sys
from PyQt5.QtWidgets import QMainWindow, QApplication


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.statusBar().showMessage('Ready')  #Crea la barra de estado con el metodo statusBar() y con showMessage() muestra un mensaje en esta.

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Statusbar')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()