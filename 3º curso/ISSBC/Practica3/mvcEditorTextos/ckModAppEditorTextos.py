#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 13:57:27 2022

@author: pabloccf
"""

from PyQt5.QtWidgets import QFileDialog, QTreeView, QListView, QFileSystemModel
from pathlib import Path

def doubleClickedTreeView(self, index):
    filePath = self.fileSystemModel.filePath(index)
    if filePath:
        with open(filePath, 'r') as f:
            filedata = f.read()
            
    return filedata

def openFile(self):
    homeDir = str(Path.home())
    self.fileName = QFileDialog.getOpenFileName(self, 'Open File', homeDir)
    
    if self.fileName[0]:
        f = open(self.fileName[0], 'r')
        
        with f:
            filedata = f.read()
            return filedata


def openFolder(self):
    directory = str(QFileDialog.getExistingDirectory(self, "Select Directory"))
    return directory
    

def saveFile(self):
    if self.fileName == ["Text Editor", ".txt"]:
        self.saveAsFiles()
    
    else:
        f = open(self.fileName[0], 'w')
        filedata = self.textEdit.toPlainText()
        f.write(filedata)
        f.close()
    
    
def saveAsFile(self):
    home_dir = str(Path.home())
    self.fileName = QFileDialog.getSaveFileName(self, 'Save File', home_dir)
    
    if self.fileName[0]:
        with open(self.fileName[0], 'w') as f:
            filedata = self.textEdit.toPlainText()
            f.write(filedata)
            f.close()