from random import randint, sample

t = 1
print(t)
for _ in range(t):
	n, m = randint(1,3), randint(7,10)
	print(n, m)
	for i in sorted(sample(range(1,20), m)):
		print(i)
