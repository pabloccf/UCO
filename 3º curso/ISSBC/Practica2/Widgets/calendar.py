#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This example shows a QCalendarWidget widget.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este programa tiene un widget de calendario y un widget de etiqueta. La fecha actualmente seleccionada se muestra en el widget de etiqueta.

from PyQt5.QtWidgets import (QWidget, QCalendarWidget,
                             QLabel, QApplication, QVBoxLayout)
from PyQt5.QtCore import QDate
import sys


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        vbox = QVBoxLayout(self)

        cal = QCalendarWidget(self)  #Crea el QCalendarWidget.
        cal.setGridVisible(True)
        cal.clicked[QDate].connect(self.showDate)  #Si seleccionamos una fecha del widget, se emite una senal de click QDate. Conectamos esta senal al metodo showDate definido por el usuario.

        vbox.addWidget(cal)

        self.lbl = QLabel(self)
        date = cal.selectedDate()  #Recupera la fecha seleccionada.
        self.lbl.setText(date.toString())

        vbox.addWidget(self.lbl)

        self.setLayout(vbox)

        self.setGeometry(300, 300, 350, 300)
        self.setWindowTitle('Calendar')
        self.show()

    def showDate(self, date):
        self.lbl.setText(date.toString())  #Transformamos el objeto de fecha en una cadena y lo configuramos en el widget de etiqueta.


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()