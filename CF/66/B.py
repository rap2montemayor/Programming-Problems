n = int(input())
garden = [int(x) for x in input().split()]

ans = 0
for i in range(n):
    # Try watering from i
    
    # to the left
    cur = 1
    j = i
    while j-1 >= 0:
        if garden[j] >= garden[j-1]:
            cur += 1
        else:
            break
        j -= 1

    j = i
    while j+1 < n:
        if garden[j] >= garden[j+1]:
            cur += 1
        else:
            break
        j += 1

    ans = max(ans,cur)

print(ans)
