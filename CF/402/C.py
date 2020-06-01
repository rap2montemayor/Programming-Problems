for t in range(int(input())):
    n, p = (int(x) for x in input().split())
    g = [[0]*n for i in range(n)]

    for i in range(n):
        g[i][(i+1)%n] = g[(i+1)%n][i] = 1
        g[i][(i+2)%n] = g[(i+2)%n][i] = 1

    for i in range(n):
        for j in range(i+1, n):
            if g[i][j] == 0:
                g[i][j] = 1
                p -= 1
            if p <= 0: break
        if p <= 0: break
    
    for i in range(n):
        for j in range(i+1, n):
            if g[i][j] == 1:
                print(i+1,j+1)