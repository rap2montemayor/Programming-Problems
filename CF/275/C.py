n, k = (int(x) for x in input().split())
a = [int(x) for x in input().split()]
exclude = set()
ans = 0

a.sort()
for i in a:
    if i not in exclude:
        exclude.add(i*k)
        ans += 1

print(ans)