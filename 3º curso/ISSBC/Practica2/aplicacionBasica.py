#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 14 20:23:55 2022

This program creates a basic application that contains an options menu, a toolbar, a status bar and a window with various controls.

@author: pabloccf
"""

import sys
from PyQt5.QtWidgets import QApplication, QMessageBox, QAction, QMainWindow, QLabel, QSlider
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import Qt

class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        exitAct = QAction(QIcon('exit_icon.png'), 'Exit', self)
        exitAct.setShortcut('Ctrl+Q')
        exitAct.setStatusTip('Exit application')
        exitAct.triggered.connect(self.close)

        self.statusBar()

        menubar = self.menuBar()
        fileMenu = menubar.addMenu('&File')
        fileMenu.addAction(exitAct)

        toolbar = self.addToolBar('Exit')
        toolbar.addAction(exitAct)
        
        sld = QSlider(Qt.Horizontal, self)
        sld.setFocusPolicy(Qt.NoFocus)
        sld.setGeometry(30, 80, 200, 30)
        sld.valueChanged[int].connect(self.changeValue)

        self.label = QLabel(self)
        self.label.setPixmap(QPixmap('mute_icon.png'))
        self.label.setGeometry(150, 120, 300, 250)
        
        self.setGeometry(400, 400, 450, 400)
        self.setWindowTitle('Main window')
        self.show()
        
    def closeEvent(self, event):
        
        reply = QMessageBox.question(self, 'Message',
                                     "¿Estas seguro de que quieres salir?", QMessageBox.Yes |
                                     QMessageBox.No, QMessageBox.Yes)
        
        if reply == QMessageBox.Yes:

            event.accept()
        else:

            event.ignore()
            
    def changeValue(self, value):

        if value == 0:

            self.label.setPixmap(QPixmap('mute_icon.png'))
        elif 0 < value <= 30:

            self.label.setPixmap(QPixmap('min_sound_icon.png'))
        elif 30 < value < 80:

            self.label.setPixmap(QPixmap('med_sound_icon.png'))
        else:

            self.label.setPixmap(QPixmap('max_sound_icon.png'))

def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()