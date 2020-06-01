def countEven(a):
    res = 0
    for i in a:
        if i%2 == 0:
            res += 1
    return res

for t in range(int(input())):
    n = int(input())
    a = sorted([int(x) for x in input().split()])
    even = countEven(a)
    ans = '?'
    if even % 2 == 0:
        ans = 'YES'
    else:
        for i in range(1,len(a)):
            if abs(a[i]-a[i-1]) == 1:
                ans = 'YES'
                break
            else:
                ans = 'NO'
    
    print(ans)