for i in range(int(input())):
    n = int(input())
    half = n//2
    if half % 2 == 1:
        print("NO")
        continue
    
    total = sum(2*x for x in range(1,half+1))
    remain = total - sum(2*x-1 for x in range(1,half))
    
    print("YES")
    print(*(2*x for x in range(1,half+1)),end=' ')
    print(*(2*x-1 for x in range(1,half)),remain)

