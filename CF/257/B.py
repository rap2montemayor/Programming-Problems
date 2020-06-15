r, b = (int(x) for x in input().split())
res = []

res.append('b')
b -= 1
for i in range(r+b):
    if i%2==1:
        # Petya's turn
        if (b < r and b > 0) or r == 0:
            b -= 1
            res.append('b')
        else:
            r -= 1
            res.append('r')
    else:
        # Vasya's turn
        if (b > r and b > 0) or r == 0:
            b -= 1
            res.append('b')
        else:
            r -= 1
            res.append('r')

print(res)
p, v = 0, 0
for i in range(1, len(res)):
    if res[i] == res[i-1]:
        p += 1
    else:
        v += 1
print(r, b)
print(p, v)