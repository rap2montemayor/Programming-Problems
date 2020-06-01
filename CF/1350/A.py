for i in range(int(input())):
    a, b = (int(x) for x in input().split())
    l = min(2*a, 2*b)
    for i in range(201):
        if i >= l and i >= max(a,b):
            print(i*i)
            break