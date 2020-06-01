a,b,c,k = (int(x) for x in input().split())
ans = min(a,k)
k -= a
if k > 0:
    k -= b
if k > 0:
    ans -= min(c,k)

print(ans)