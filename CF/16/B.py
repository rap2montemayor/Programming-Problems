n, m = [int(x) for x in input().split()]
container = []

for i in range(m):
    ai, bi = [int(x) for x in input().split()]
    container.append((bi,ai))

container.sort()
container = container[::-1]

ans = 0
for i in container:
    amt = min(i[1],n)
    ans += i[0] * amt
    n -= amt

    if n<=0:
        break

print(ans)

