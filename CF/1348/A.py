for t in range(int(input())):
    n = int(input())
    a, b = 1<<n, 0
    for i in range(1,n//2):
        a += 1<<i
    for i in range(n//2, n):
        b += 1<<i
    print(abs(a-b))