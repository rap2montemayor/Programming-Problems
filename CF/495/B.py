def count(n, x):
	if n == 1 and x < 1: return 1

	res = 0
	for i in range(1, n):
		if i*i > n:	break

		if n % i == 0:
			if i > x:
				res += 1
			if n//i > x and n//i != i:
				res += 1
			
	return res

a, b = (int(x) for x in input().split())
if a == b: print("infinity")
else: print(count(a-b, b))

