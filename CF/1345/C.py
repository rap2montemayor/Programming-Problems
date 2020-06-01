for t in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    count = dict()
    res = True
    for i in range(2*n+1):
        if i+a[i%n]%n not in count:
            count[i+a[i%n]%n] = 0

        count[i+a[i%n]%n] += 1
        if count[i+a[i%n]%n] > 1:
            res = False
            break
        
    if res: print("YES")
    else: print("NO")