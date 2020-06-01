def getCards(height):
    return 3*height*(height+1)//2 - height

def getHeight(n):
    l, r = 0, n
    while l < r:
        m = (l+r)//2
        obj = getCards(m)
        if obj > n:
            r = m
        else:
            l = m+1
    return l-1

for t in range(int(input())):
    n = int(input())
    ans = 0
    while n > 1:
        n -= getCards(getHeight(n))
        ans += 1
    print(ans)
