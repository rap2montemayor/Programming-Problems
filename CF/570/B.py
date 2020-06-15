n, m = (int(x) for x in input().split())
if n == 1:
    print(1)
else:
    print(m-1 if m*2 > n else m+1)