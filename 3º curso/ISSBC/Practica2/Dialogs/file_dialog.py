#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

In this example, we select a file with a
QFileDialog and display its contents
in a QTextEdit.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa muestra una barra de menu, un widget de edicion de texto centralizado y una barra de estado. El elemento del menu muestra el QFileDialog que se utiliza para seleccionar un archivo. El contenido del archivo se carga en el widget de edicion de texto.

from PyQt5.QtWidgets import (QMainWindow, QTextEdit,
                             QAction, QFileDialog, QApplication)
from PyQt5.QtGui import QIcon
import sys
from pathlib import Path


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.textEdit = QTextEdit()
        self.setCentralWidget(self.textEdit)
        self.statusBar()

        openFile = QAction(QIcon('open.png'), 'Open', self)
        openFile.setShortcut('Ctrl+O')
        openFile.setStatusTip('Open new File')
        openFile.triggered.connect(self.showDialog)

        menubar = self.menuBar()
        fileMenu = menubar.addMenu('&File')
        fileMenu.addAction(openFile)

        self.setGeometry(300, 300, 550, 450)
        self.setWindowTitle('File dialog')
        self.show()

    def showDialog(self):

        home_dir = str(Path.home())  #Devuelve la version de la cadena del objeto dado.
        fname = QFileDialog.getOpenFileName(self, 'Open file', home_dir)  #Abrimos el QFileDialog. La primera cadena del metodo getOpenFileName es el titulo, la segunda cadena especifica el directorio de trabajo del dialogo.

        if fname[0]:
            f = open(fname[0], 'r')  #Abre un archivo o fichero.

            with f:
                data = f.read()  #Lee el nombre del archivo seleccionado.
                self.textEdit.setText(data)  #Establece el contenido del archivo en el widget de edicion de texto.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()