from sys import argv
import string

alfabeto = list(string.ascii_uppercase)

with open(argv[1], 'r') as f_in:
    txt_in = f_in.read()
    
for clave in range(1, len(alfabeto)):
    texto_descifrado = ""
    for letra in txt_in.upper():
        if letra in alfabeto:
            indice_actual = alfabeto.index(letra)
            indice_cesar = indice_actual + clave
            indice_cesar %= len(alfabeto)
            texto_descifrado += alfabeto[indice_cesar]
        else:
            texto_descifrado += letra

    print(f"Clave {clave}: {texto_descifrado}")
