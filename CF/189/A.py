n, a, b, c = (int(x) for x in input().split())
lens = sorted([a, b, c])

parts = n // lens[0]
n = n % lens[0]

ans = parts if n == 0 else 0
while parts > 0:
	n += lens[0]
	parts -= 1

	temp = n
	count = 0
	while temp - lens[1] >= 0:
		temp -= lens[1]
		count += 1
		if temp % lens[2] == 0:
			ans = max(ans, parts + count + temp//lens[2])
	temp = n
	count = 0
	while temp - lens[2] >= 0:
		temp -= lens[2]
		count += 1
		if temp % lens[1] == 0:
			ans = max(ans, parts + count + temp//lens[1])

print(ans)

