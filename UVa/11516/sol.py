def countrouters(h, r):
	count, edge = 0, -2e9
	for i in range(len(h)):
		if (h[i] <= edge):
			continue

		count += 1
		edge = h[i] + r * 2

	return count

def bsearch(h, n):
	l, r = 0, h[-1]

	for _ in range(100):
		m = (r+l)/2
		a = countrouters(h, m)
		if a <= n: r = m
		else: l = m

	return l

t = int(input())

for _ in range(t):
	n, m = (int(x) for x in input().split())
	h = [0] * m
	for i in range(m):
		h[i] = int(input())
	h.sort()

	print(f"{bsearch(h, n):.1f}")
	
