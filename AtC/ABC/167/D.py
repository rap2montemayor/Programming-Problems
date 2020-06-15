def detectCycle(a):
    start, length = 0, 1
    p1, p2 = a[1], a[a[1]]
    while p1 != p2:
        p1, p2 = a[p1], a[a[p2]]
    
    p2 = 1
    while p1 != p2:
        p1, p2 = a[p1], a[p2]
        start += 1
    
    p2 = a[p1]
    while p1 != p2:
        p2 = a[p2]
        length += 1
    
    return start, length

n, k = (int(x) for x in input().split())
a = [-1] + [int(x) for x in input().split()]
start, length = detectCycle(a)

loc = 1
for i in range(min(start,k)):
    loc = a[loc]
k = max(k-start,0)

k %= length
for i in range(k):
    loc = a[loc]
print(loc)
