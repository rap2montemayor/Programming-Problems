for t in range(int(input())):
    n, m = (int(x) for x in input().split())
    if n == 1 or m == 1: print("YES")
    elif n == 2 and m == 2: print("YES")
    else: print("NO")