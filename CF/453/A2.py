m, n = (int(x) for x in input().split())
ans = 0
for i in range(1, m+1):
	ans += i * (i**n - (i-1)**n)
print(ans/m**n)