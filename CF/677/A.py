n,h = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

ans = 0
for i in a:
    if i > h: ans += 2
    else: ans += 1
print(ans)