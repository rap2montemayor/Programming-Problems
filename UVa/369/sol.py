comb = [[1]*101 for i in range(101)]
for i in range(2,101):
    for j in range(1,i):
        comb[i][j] = comb[i-1][j-1] + comb[i-1][j]

while True:
    n,m = (int(x) for x in input().split())
    if n==0 and m==0: break
    print(f"{n} things taken {m} at a time is {comb[n][m]} exactly.")
