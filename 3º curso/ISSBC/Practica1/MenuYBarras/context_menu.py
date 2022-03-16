#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program creates a context menu.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa crea un menu contextual.

import sys
from PyQt5.QtWidgets import QMainWindow, qApp, QMenu, QApplication


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Context menu')
        self.show()

    def contextMenuEvent(self, event):
        cmenu = QMenu(self)

        newAct = cmenu.addAction("New")
        openAct = cmenu.addAction("Open")
        quitAct = cmenu.addAction("Quit")
        action = cmenu.exec_(self.mapToGlobal(event.pos()))  #Muestra el menu contextual y con el metodo mapToGlobal traduce las coordenadas del widget a las coordenadas de la pantalla.

        if action == quitAct:
            qApp.quit()
        #Este if realiza la opcion de terminar la aplicacion si la accion devuelta desde el menu contextual es igual a la accion de salir.

def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()