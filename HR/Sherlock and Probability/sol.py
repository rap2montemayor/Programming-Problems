def getPrefSum(s):
    res = [0]
    for c in s:
        res.append(int(c) + res[-1])
    return res

def count(s, k):
    res = 0
    if k >= len(s):
        return s[-1] + s[-1]*(s[-1]-1)

    for i in range(k,len(s)):
        sub = s[i] - s[i-k]
        res += sub + sub*(sub-1)

    if k < len(s)-1:
        for i in range(k,len(s)-1):
            sub = s[i] - s[i-k+1]
            res -= sub + sub*(sub-1)
    
    return res

def gcd(a, b):
    return b if a==0 else gcd(b%a, a)

for t in range(int(input())):
    n, k = (int(x) for x in input().split())
    s = getPrefSum(input())
    num = count(s, k+1)
    denom = n*n
    div = gcd(num, denom)

    num //= div
    denom //= div

    print(num,'/',denom,sep='')