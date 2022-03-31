#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 13:55:01 2022

@author: pabloccf
"""

import sys
from PyQt5 import QtWidgets
import ckVtsEditorTextos as vts

app = QtWidgets.QApplication(sys.argv) #Crea una aplicacion.
form = vts.EditorTextosDlg()   #Crea una instancia del formulario.
sys.exit(app.exec_())   #Se inicia la aplicacion y se esperan eventos.