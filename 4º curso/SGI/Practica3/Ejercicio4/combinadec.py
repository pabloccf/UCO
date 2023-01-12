import string
from sys import argv
import zipfile
import os

alfabeto = list(string.ascii_lowercase) + list(string.ascii_uppercase)

def cifrado_caesar(alfabeto, n, texto):
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


zFile = zipfile.ZipFile(argv[1])
zFile.extractall()

with open(argv[1].replace(".zip", ".txt"), 'r') as f:
    frase = f.read()
    
frase_descifrada = cifrado_caesar(alfabeto, len(alfabeto)-3, frase)

if argv[2] == '-o':
    with open(argv[3], 'w') as f:
        f.write(frase_descifrada)

os.remove(argv[1].replace(".zip", ".txt"))
