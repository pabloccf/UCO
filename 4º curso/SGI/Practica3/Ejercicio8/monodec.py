import string
import random
from sys import argv

clave = random.randint(1,25)
print('clave generada aleatoriamente para encriptar: ' + str(clave))

alfabeto = list(string.ascii_uppercase)

def monoEnc(alfabeto, n, texto):
    texto_cifrado = ""
    for letra in texto:
        if letra in alfabeto:
            indice_actual = alfabeto.index(letra)
            indice_cesar = indice_actual + n
            indice_cesar %= len(alfabeto)
            texto_cifrado += alfabeto[indice_cesar]
        else:
            texto_cifrado += letra
    return texto_cifrado

with open(argv[1], 'r') as f_in:
    txt_in = f_in.read().upper()

    txt_out = ""
    txt_out = monoEnc(alfabeto, len(alfabeto) - clave, txt_in)
    
    
    if argv[2] == '-o':
        with open(argv[3], 'w') as f_out:
            f_out.write(txt_out)