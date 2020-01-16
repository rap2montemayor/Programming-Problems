def xorRange(x):
    #0^1^2^...^x
    if x%4 == 0:
        return x
    if x%4 == 1:
        return 1
    if x%4 == 2:
        return x+1
    if x%4 == 3:
        return 0

def f(a,b):
    return xorRange(a-1) ^ xorRange(b)

a,b = [int(x) for x in input().split()]
print(f(a,b))

