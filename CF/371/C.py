recipe = input()
reqs = [recipe.count(x) for x in "BSC"]
counts = [int(x) for x in input().split()]
prices = [int(x) for x in input().split()]
money = int(input())

burgerPrice = sum(reqs[i]*prices[i] for i in range(3))
cur, match = 1e12, 0
for i in range(3):
    if reqs[i]==0: continue
    cur = min(cur, counts[i]//reqs[i])
    match = max(match, counts[i]//reqs[i])

while cur <= match and money >= min(prices):
    cur += 1
    for i in range(3):
        if reqs[i]==0: continue
        if counts[i]//reqs[i] < cur and money >= prices[i]:
            money -= prices[i]
            counts[i] += 1

ans = 1e12
for i in range(3):
    if reqs[i]==0: continue
    ans = min(ans, counts[i]//reqs[i])
ans += money//burgerPrice
print(ans)
    