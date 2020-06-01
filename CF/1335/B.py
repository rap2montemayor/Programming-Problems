for t in range(int(input())):
    n,a,b = (int(x) for x in input().split())
    substr = "abcdefghijklmnopqrstuvwxyz"[:b]
    print(substr*(n//b) + substr[:n%b])
