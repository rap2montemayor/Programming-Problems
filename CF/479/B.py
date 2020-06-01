n, k = (int(x) for x in input().split())
a = [int(x) for x in input().split()]

output = []
instability, moves = max(a) - min(a), 0
while moves < k:
    high, low = max(a), min(a)
    h, l = a.index(max(a)), a.index(min(a))
    if h == l: break
    a[h], a[l] = a[h]-1, a[l]+1

    moves += 1
    output.append((h+1,l+1))
    instability = max(a) - min(a)

print(instability,moves)
for p in output:
    print(*(x for x in p))