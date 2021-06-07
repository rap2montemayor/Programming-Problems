from math import ceil, sqrt
r, x, y = (int(x) for x in input().split())
print(ceil(sqrt((x*x + y*y)/(r*r))) if r*r <= x*x + y*y else 2)