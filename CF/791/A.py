lim, bob = [int(x) for x in input().split()]

ans = 0
while lim <= bob:
    lim *= 3
    bob *= 2
    ans += 1

print(ans)
