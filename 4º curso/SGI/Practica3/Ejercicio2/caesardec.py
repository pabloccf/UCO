import string
from sys import argv

alfabeto = list(string.ascii_lowercase) + list(string.ascii_uppercase)

def decodificado_caesar(alfabeto, n, texto):
    texto_decodificado = ""
    for letra in texto:
        if letra in alfabeto:
            indice_cesar = alfabeto.index(letra)
            indice_original = indice_cesar + n
            indice_original %= len(alfabeto)
            texto_decodificado += alfabeto[indice_original]
        else:
            texto_decodificado += letra
            
    return texto_decodificado

with open(argv[1], 'r') as f:
    frase_cifrada = f.read()
    
frase_descifrada = decodificado_caesar(alfabeto, len(alfabeto)-3, frase_cifrada)

if argv[2] == '-o':
    with open(argv[3], 'w') as file:
        frase2 = file.write(frase_descifrada)