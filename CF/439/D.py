def f(mid, a, b):
    ans=0
    for i in a:
        if i < mid: ans+=mid-i
    for i in b:
        if i > mid: ans+=i-mid
    return ans

n,m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

for i in range(10):
    print(i,f(i,a,b))
