for t in range(1, int(input())+1):
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]

    ans = 0
    l, r = 0, n-1
    while l < r:
        if a[l] == a[r]:
            l += 1
            r -= 1
        else:
            l += 1
            ans += 1
    
    print(f'Case {t}: ', end='')
    if ans == 0:
        print('Too easy')
    elif ans > k:
        print('Too difficult')
    else:
        print(ans)
