for t in range(int(input())):
    n = int(input())
    a = sorted([int(x) for x in input().split()])
    ans = 1
    for i in range(n):
        if a[i] <= i+1:
            ans = i+2
    print(ans)