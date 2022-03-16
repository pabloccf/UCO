#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 28 00:50:40 2022

This program performs all the actions learned in the previous examples.

@author: pabloccf
"""

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QDesktopWidget, QMessageBox, QPushButton, QToolTip
from PyQt5.QtGui import QIcon, QFont

class Example(QWidget):
        
    def __init__(self):
        super().__init__()
        
        self.initUI()
    
    def initUI(self):
        
        QToolTip.setFont(QFont('SansSerif', 10))
        self.setToolTip('This is a <b>QWidget</b> widget')
        
        qbtn = QPushButton('Quit', self)
        qbtn.setToolTip('This is a <b>QPushButton</b> widget')
        qbtn.clicked.connect(QApplication.instance().quit)
        qbtn.resize(qbtn.sizeHint())
        qbtn.move(50, 50)
        
        self.resize(250, 150)
        self.center()
        
        self.setWindowTitle('Ejemplo completo')
        self.setWindowIcon(QIcon('web.png'))
        self.show()
        
    def center(self):
        
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())
    
    def closeEvent(self, event):
        
        reply = QMessageBox.question(self, 'Message',
                                     "Are you sure to quit?", QMessageBox.Yes |
                                     QMessageBox.No, QMessageBox.Yes)
        
        if reply == QMessageBox.Yes:

            event.accept()
        else:

            event.ignore()
        
def main():
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
    
if __name__ == '__main__':
    main()