for i in range(int(input())):
    x,n,m = (int(x) for x in input().split())

    for i in range(n):
        if x<=20: break
        x = x//2 + 10
    for i in range(m):
        x -= 10
        
    print("YES") if x<=0 else print("NO")