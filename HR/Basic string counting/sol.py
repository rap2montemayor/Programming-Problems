t = int(input())

for i in range(t):
    n = int(input())
    n-=1;
    if n<6:
        print(26*25**(n))
    else:
        n-=5
        print((26*25**(5+n%32))%1000000000)

