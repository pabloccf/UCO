#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 13:56:33 2022

@author: pabloccf
"""

from select import select
import sys
import ckControladorEditorTextos as ctrl
from PyQt5.QtWidgets import QWidget, QApplication, QLabel, QLineEdit, QTextEdit, QVBoxLayout, QHBoxLayout, QPushButton, QGridLayout, QMessageBox, QTreeView, QFileSystemModel

class EditorTextosDlg(QWidget):
    def __init__(self):
        super().__init__()
        self.fileName = ["Text Editor", ".txt"]
        
        self.initUI()
        
    def initUI(self):
        
        title = QLabel('Folders')

        self.fileFolder = QLineEdit()
        self.fileFolder.setReadOnly(True)
        
        self.selectButton = QPushButton("Select")
        
        files = QLabel('Files')
        
        self.fileTree = QTreeView()

        self.fileSystemModel = QFileSystemModel(self.fileTree)
        self.fileSystemModel.setReadOnly(True)
        folder = "."
        modelRoot = self.fileSystemModel.setRootPath(folder)

        self.fileTree.setModel(self.fileSystemModel)
        self.fileTree.setRootIndex(modelRoot)
        self.fileTree.hideColumn(1)
        self.fileTree.hideColumn(2)
        self.fileTree.hideColumn(3)
        self.fileTree.setHeaderHidden(True)
        
        self.textEdit = QTextEdit()
        
        self.saveButton = QPushButton("Save")
        self.saveAsButton = QPushButton("Save As")
        
        vbox = QVBoxLayout()
        vbox.setSpacing(20)
        
        hbox = QHBoxLayout()
        
        hbox.addWidget(title)
        hbox.addWidget(self.fileFolder)
        hbox.addWidget(self.selectButton)
        
        vbox.addLayout(hbox)
        
        grid = QGridLayout()
        grid.setSpacing(10)
        
        
        grid.addWidget(files, 0, 0)
        grid.addWidget(self.fileTree, 1, 0, 1, 2)
        grid.addWidget(self.textEdit, 1, 2, 1, 5)
        
        grid.addWidget(self.saveButton, 2, 0)
        grid.addWidget(self.saveAsButton, 2, 1)
        
        vbox.addLayout(grid)
        
        self.setLayout(vbox)
        
        self.setGeometry(600, 600, 800, 800)
        self.setWindowTitle("Text Editor")
        self.show()
        
        self.fileTree.doubleClicked.connect(self.fileTreeDoubleClicked)
        self.selectButton.clicked.connect(self.openFolders)
        self.saveButton.clicked.connect(self.saveFiles)
        self.saveAsButton.clicked.connect(self.saveAsFiles)
        
    def fileTreeDoubleClicked(self, index):
        filedata = ctrl.eventDoubleClickedTreeView(self, index)
        self.textEdit.setText(filedata)

    def openFolders(self):
        # Retrieve the folder path from the controller
        directory = ctrl.eventOpenFolder(self)
        
        # Display the folder content on the TreeView
        modelRoot = self.fileSystemModel.setRootPath(directory)
        self.fileTree.setRootIndex(modelRoot)

        # Display the folder path on the top QLine
        self.fileFolder.setText(directory)
            
    def saveFiles(self):
        ctrl.eventSaveFile(self)
        
    def saveAsFiles(self):
        ctrl.eventSaveAsFile(self)
        
    def listFilesFolder(self):
        ctrl.eventListFilesFolder(self)
            
    def closeEvent(self, event):
        
        reply = QMessageBox.question(self, 'Message',
                                     "Are you sure to quit?", QMessageBox.Yes |
                                     QMessageBox.No, QMessageBox.No)
        
        if reply == QMessageBox.Yes:

            event.accept()
        else:

            event.ignore()
            

if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = EditorTextosDlg()
    sys.exit(app.exec_())
            