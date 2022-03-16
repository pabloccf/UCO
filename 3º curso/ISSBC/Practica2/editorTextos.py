#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 15 12:28:46 2022

This program creates a text editor that allows us to open, modify or create a new file.

@author: pabloccf
"""

import sys
from PyQt5.QtWidgets import QMainWindow, QAction, QTextEdit, QApplication, QFileDialog, QDesktopWidget, QMessageBox
from PyQt5.QtGui import QIcon

class Main(QMainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.initUI()

    def initUI(self):
        
        newAction = QAction('New', self)
        newAction.setShortcut('Ctrl+N')
        newAction.triggered.connect(self.newFile)
        
        openAction = QAction('Open', self)
        openAction.setShortcut('Ctrl+O')
        openAction.triggered.connect(self.openFile)
        
        saveAction = QAction('Save', self)
        saveAction.setShortcut('Ctrl+S')
        saveAction.triggered.connect(self.saveFile)
        
        saveAsAction = QAction('Save As', self)
        saveAsAction.setShortcut('Ctrl+Shift+S')
        saveAsAction.triggered.connect(self.saveAsFile)
        
        menubar = self.menuBar()
        fileMenu = menubar.addMenu('File')
        fileMenu.addAction(newAction)
        fileMenu.addAction(openAction)
        fileMenu.addAction(saveAction)
        fileMenu.addAction(saveAsAction)
        
        self.txt = QTextEdit(self)
        self.setCentralWidget(self.txt)
        self.center()
        
        self.setGeometry(300,300,600,500)
        self.setWindowTitle("Text Editor")
        self.show()

    def newFile(self):
        self.txt.clear()
        
    def openFile(self):
        filename = QFileDialog.getOpenFileName(self, 'Open File')
        f = open(filename[0], 'r')
        filedata = f.read()
        self.txt.setText(filedata)
        f.close()
        
    def saveFile(self):
        filename = QFileDialog.getSaveFileName(self, 'Save File')
        f = open(filename[0], 'w')
        filedata = self.txt.toPlainText()
        f.write(filedata)
        f.close()
        
    def saveAsFile(self):
        fname = QFileDialog.getSaveFileName(self, 'Save file',)
        if fname[0]:
            f = open(fname[0], 'w')
            with f:
                data = self.textArea.toPlainText()
                f.write(data)
                f.close()
                self.filePath = fname
    
    def center(self):
        
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())
        
    def closeEvent(self, event):
        
        reply = QMessageBox.question(self, 'Message',
                                     "¿Estas seguro de que quieres salir?", QMessageBox.Yes |
                                     QMessageBox.No, QMessageBox.Yes)
        
        if reply == QMessageBox.Yes:

            event.accept()
        else:

            event.ignore()

def main():
    app = QApplication(sys.argv)
    main = Main()
    main.show()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()