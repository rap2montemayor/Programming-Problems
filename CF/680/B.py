n, a = [int(x) for x in input().split()]
t = [1] + [int(x) for x in input().split()] + [1]

l = a - 1
r = a + 1

ans = t[a]

while l > 0 or r <= n:
    if t[l] == 1 and t[r] == 1:
        ans += 2
        if l == 0 or r == n + 1:
            ans -= 1

    if l > 0:
        l -= 1
    if r <= n:
        r += 1

print(ans)
