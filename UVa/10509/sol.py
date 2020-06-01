def geta(n):
    if n == 1: return 1

    l, r, m = 0, n, n
    while (l < r):
        m = (l + r) // 2
        if m*m*m < n: l = m+1
        elif m*m*m > n : r = m
        else: break
    
    if m*m*m > n: m -= 1
    return m

def cbrt(n):
    a = geta(n)
    num = n-a*a*a
    denom = 3*a*a
    return a + num/denom

while True:
    n = float(input())
    if n == 0: break
    print('{:.4f}'.format(cbrt(n)))