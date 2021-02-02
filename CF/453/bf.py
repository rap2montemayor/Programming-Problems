#m, n = (int(x) for x in input().split())

print("input m")
m = int(input())
aaa = [0]*(m+1)
for i in range(1,m+1):
	for j in range(1,m+1):
		for k in range(1,m+1):
			for l in range(1,m+1):
				aaa[max(i,j,k,l)] += 1

print(aaa)
aaa = [0]*(m+1)
for i in range(1,m+1):
	aaa[i] = i**3 + (i**3-(i-1)**3)*(i-1)
print(aaa)
