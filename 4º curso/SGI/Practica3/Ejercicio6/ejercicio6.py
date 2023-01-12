from sys import argv
import string

alfabeto = list(string.ascii_uppercase)
texto_cifrado = "ls jvukl lzAh hs shkv kl sh jhzh kl tp hiBlsh Myhujpzjh NBAplyylG"

for clave in range(1, len(alfabeto)):
    texto_descifrado = ""
    for letra in texto_cifrado.upper():
        if letra in alfabeto:
            indice_actual = alfabeto.index(letra)
            indice_cesar = indice_actual + clave
            indice_cesar %= len(alfabeto)
            texto_descifrado += alfabeto[indice_cesar]
        else:
            texto_descifrado += letra

    print(f"Clave {clave}: {texto_descifrado}")
