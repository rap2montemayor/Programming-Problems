a = int(input())
if a == 1 or a == 2:
    print(-1)
elif a % 4 == 0 and a != 4:
    b = ((a//2)**2 - 4) // 2
    c = ((a//2)**2 + 4) // 2
    print(b,c)
elif a % 2 == 0:
    a //= 2
    b = (a**2 - 1)
    c = (a**2 + 1)
    print(b,c)
else:
    b = (a**2 - 1) // 2
    c = (a**2 + 1) // 2
    print(b,c)