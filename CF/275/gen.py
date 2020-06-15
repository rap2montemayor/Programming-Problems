from random import randint

n = 10
k = randint(1,5)
a = set()
for i in range(n):
    maxa = 15
    toadd = randint(1,maxa)
    while toadd in a:
        toadd = randint(1,maxa)
    a.add(toadd)

print(n, k)
print(*(i for i in a))