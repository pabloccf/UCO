from collections import Counter
from sys import argv

with open(argv[1], 'r') as f_in:
    txt_in = f_in.read()
    
res = Counter(txt_in)

print("El recuento de todos los caracteres del fichero es : \n " + str(res))