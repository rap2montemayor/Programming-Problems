for t in range(int(input())):
    n, m = (int(x) for x in input().split())
    squares = n*m
    if squares%2 == 0: print(squares//2)
    else: print(squares//2 + 1)