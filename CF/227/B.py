n = int(input())
a = [int(x) for x in input().split()]
m = int(input())
b = [int(x) for x in input().split()]

idx = [0]*100001
for i in range(len(a)):
    idx[a[i]] = i

v, p = 0, 0
for query in b:
    v += abs(0 - idx[query]) + 1
    p += abs(n - idx[query])

print(v, p)
