#!/usr/bin/python

"""
ZetCode PyQt5 tutorial

This program shows a confirmation
message box when we click on the close
button of the application window.

Author: Jan Bodnar
Website: zetcode.com
"""

#Este codigo abre una ventana emergente que cuando le das a cerrar te sale un mensaje de confirmacion de cierre y dependiendo la opcion que se pulse cerrara o no la ventana.

import sys  #Este modulo se encarga de suministrar las variables y funcionalidades relacionadas con el interprete.
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication  #En este modulo tenemos los widgets basicos.


class Example(QWidget):  #Se define la clase Example con los metodos init y initUI. Ademas la clase Example hereda de la clase QWidget.

    def __init__(self):  #Invoca al metodo init de la superclase, QWidget, para heredar.
        super().__init__()  #Esta funcion nos permite invocar y conservar un metodo de una clase padre desde una clase hija sin tener que nombrarla explicitamente.

        self.initUI()  #Hace referencia a la propia clase e invoca al metodo initUI.

    def initUI(self):  #Invoca al metodo initUI de la superclase, QWidget, para heredar.

        self.setGeometry(300, 300, 250, 150)  #Establece las dimensiones de la ventana.
        self.setWindowTitle('Message box')  #Establece el titulo de la ventana y este se muestra en la barra disponible para ello.
        self.show()  #Este metodo muestra el widget en la pantalla pero primero se crea en la memoria y despues se muestra en la pantalla.

    def closeEvent(self, event):  #Invoca al metodo closeEvent de la superclase, QWidget, para heredar.

        reply = QMessageBox.question(self, 'Message',
                                     "Are you sure to quit?", QMessageBox.Yes |
                                     QMessageBox.No, QMessageBox.No)  #Crea una ventana emergente, en el que el segundo argumento es el titulo de la ventana, el tercero es el mensaje, el cuarto son las opciones y el ultimo la opcion predeterminada. 

        if reply == QMessageBox.Yes:

            event.accept()
        else:

            event.ignore()
        #En este if y else probamos el valor de retorno, es decir, si se pulsa en el si, se acepta el evento y se cierra el widget, y de lo contrario, ignoramos el evento de cierre del widget.

def main():  #Define la funcion principal, funcion main.
    app = QApplication(sys.argv)  #Creamos una instancia de una clase. El parametro sys.argv es una lista de argumentos de una linea de comandos.
    ex = Example()  #Crea una instancia de la clase Example().
    sys.exit(app.exec_())  #Salimos de la clase y el sistema queda a la espera de que se produzca una interrupcion. Ademas este metodo asegura una salida limpia.


if __name__ == '__main__':  #Esta linea de codigo se ejecuta si es el modulo principal pero en el caso de que estuviera importado no se ejecutaria.
    main()  #Invoca a la funcion main.