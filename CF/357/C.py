n, m = (int(x) for x in input().split())
ans = [0 for x in range(n+2)]
nxt = [x+1 for x in range(n+2)]

for i in range(m):
    l, r, x = (int(a) for a in input().split())
    while l <= r:
        if ans[l] == 0 and l != x:
            ans[l] = x
        l = nxt[l]
    nxt[x] = nxt[r]

print(*(x for x in ans[1:n+1]))
