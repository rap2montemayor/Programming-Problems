def evalPoly(poly, x):
    ans = 0
    for i in range(len(poly)):
        ans += poly[i] * x**(len(poly)-1-i)
    return ans

while True:
    try: poly = [int(x) for x in input().split()]
    except: break
    print(*(evalPoly(poly,int(x)) for x in input().split()))
    