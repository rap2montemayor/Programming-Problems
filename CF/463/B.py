n = int(input())
h = [int(x) for x in input().split()]

ans = 0
for i in h:
    ans = max(ans,i)
print(ans)
