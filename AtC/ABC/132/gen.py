n = 317
m = n * (n-1)

print(n, m)
for u in range(1, n+1):
	for v in range(1, n+1):
		if u == v:
			continue
		print(u, v)

print(1, n)
