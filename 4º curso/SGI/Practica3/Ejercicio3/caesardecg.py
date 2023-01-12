from sys import argv
import string

alfabeto = list(string.ascii_lowercase) + list(string.ascii_uppercase)

def algoritmo_caesar(alfabeto, n, texto):
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


with open(argv[2], 'r') as f_in:
    txt_in = f_in.read()

    txt_out = ""
    txt_out = algoritmo_caesar(alfabeto, len(alfabeto)-int(argv[1]), txt_in)

    if argv[3] == '-o':
        with open(argv[4], 'w') as f_out:
            f_out.write(txt_out)