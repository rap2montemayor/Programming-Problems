m = int(1e9+7)
fac = [1]*int(2e5+1)
for i in range(1,int(2e5+1)): fac[i] = (fac[i-1]*i)%m

def modpow(n, x):
    if n==1 or x==0: return 1
    if x==1: return n
    res = 1
    n %= m
    while (x>0):
        if x%2==1: res = (res*n)%m
        x //= 2
        n = (n*n)%m
    return res

def inverse(n):
    return modpow(n,m-2)

def comb(n, r):
    if n==r or n==0: return 1
    num = fac[n]
    denom = (fac[r]*fac[n-r])%m
    return (num*inverse(denom))%m

n,k = [int(x) for x in input().split()]
balls = sorted([int(x) for x in input().split()])

ans=0
for i in range(n-k+1):
    c = comb(n-i-1,k-1)
    ans = (ans - (balls[i]*c)%m + (balls[n-i-1]*c)%m)%m

print(ans)
