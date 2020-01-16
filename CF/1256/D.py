t = int(input())
for x in range(t):
    n,k = [int(i) for i in input().split()]
    s = list(input())
    moves=0
    sorted=0
    for i in range(n):
        if moves>=k: break
        if s[i]=="0":
            s[i]='1'
            if moves+i-sorted <= k:
                s[sorted]='0'
            else:
                s[i-k+moves]='0'
            moves+=i-sorted
            sorted+=1
    for c in s:
        print(c,end='')
    print()
