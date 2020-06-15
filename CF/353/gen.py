from random import randint

n = int(2)
a = [randint(0,5) for i in range(n)]
b = [randint(0,1) for i in range(n)]

print(n)
print(*(i for i in a))
print(*(i for i in b),sep='')