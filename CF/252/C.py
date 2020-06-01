n, d = (int(x) for x in input().split())
x = [int(i) for i in input().split()]

r = 0
ans = 0
for l in range(n):
    while r < n-1 and abs(x[r] - x[l]) <= d:
        r += 1
    if abs(x[r] - x[l]) > d and r > l+1:
        r -= 1
    temp = r - l - 1
    if temp <= 0: continue
    ans += temp * (temp+1) // 2
print(ans)