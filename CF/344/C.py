def gcd(a,b): return 0 if b == 0 else a//b + gcd(b, a%b)
print(gcd(*(int(x) for x in input().split())))