n = int(input())

ans = 0
for i in range(n):
    hatdog = sum([int(x) for x in input().split()])
    if hatdog > 1:
        ans += 1

print(ans)
