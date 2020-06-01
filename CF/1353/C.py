for t in range(int(input())):
    n = int(input())
    layers = n//2
    ans = 0
    for i in range(1,layers+1):
        ans += i*i*2*4
    print(ans)