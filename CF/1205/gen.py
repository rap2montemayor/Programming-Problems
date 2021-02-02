from random import randint

n = int(1e4)
print(n)
print(*(int(2**60-1) for i in range(n)))