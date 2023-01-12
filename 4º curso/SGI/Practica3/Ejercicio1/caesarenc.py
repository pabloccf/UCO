import string
from sys import argv

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

with open(argv[1], 'r') as f:
    frase = f.read()
    
frase_cifrada = cifrado_caesar(alfabeto, 3, frase)

if argv[2] == '-o':
    with open(argv[3], 'w') as file:
        frase2 = file.write(frase_cifrada)