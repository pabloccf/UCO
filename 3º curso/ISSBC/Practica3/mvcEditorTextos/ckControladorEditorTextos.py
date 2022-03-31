#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 13:56:59 2022

@author: pabloccf
"""

import ckModAppEditorTextos as mapp

def eventDoubleClickedTreeView(self, index):
    data = mapp.doubleClickedTreeView(self, index)
    return data

def eventOpenFolder(self):
    data = mapp.openFolder(self)
    return data

def eventSaveFile(self):
    data = mapp.saveFile(self)
    return data

def eventSaveAsFile(self):
    data = mapp.saveAsFile(self)
    return data