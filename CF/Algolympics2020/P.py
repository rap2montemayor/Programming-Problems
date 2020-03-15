def gcd(a,b):
    if b==0: return a
    else: return gcd(b, a%b)

t = int(input())

for i in range(t):
    k,b = [int(x) for x in input().split()]
    #k and b have a common factor
    if gcd(k,b-1)==1: print("COOL")
    else: print("NOT COOL")
