from random import randint
n = int(5)
print(n)
print(*(randint(0,10) for _ in range(n)))