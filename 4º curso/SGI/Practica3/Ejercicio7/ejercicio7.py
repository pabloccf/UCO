import random
import string

alfabeto = list(string.ascii_lowercase)
random.shuffle(alfabeto)
result = ''.join(alfabeto)

print(result)