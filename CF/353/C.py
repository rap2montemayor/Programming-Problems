def makePref(a):
    pref = a[:]
    for i in range(1,len(pref)):
        pref[i] += pref[i-1]
    return pref

def makeSuff(a, m):
    suff = a[:]
    for i in range(len(suff)):
        suff[i] *= m[i]
    for i in range(len(suff)-2, -1, -1):
        suff[i] += suff[i+1]
    return suff

def solve(pref, suff, m):
    ans = suff[0]
    for i in range(1,len(m)):
        if m[i] == 1:
            if i == len(m)-1:
                ans = max(ans, pref[i-1])
            else:
                ans = max(ans, pref[i-1] + suff[i+1])
    return ans

n = int(input())
a = [int(x) for x in input().split()]
m = [int(x) for x in input()]

pref = makePref(a)
suff = makeSuff(a, m)
print(solve(pref, suff, m))