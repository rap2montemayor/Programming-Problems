from math import gcd

a, b = (int(x) for x in input().split())
upper = a * b / gcd(a,b)
m, d = upper/b, upper/a
if a < b: d -= 1
else: m -= 1

if d > m: print("Dasha")
elif m > d: print("Masha")
else: print("Equal")
