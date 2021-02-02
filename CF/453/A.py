m, n = (int(x) for x in input().split())
ans = 0
for i in range(1, m+1):
	ans += i * (i/m)**n - i*((i-1)/m)**n
print(ans)