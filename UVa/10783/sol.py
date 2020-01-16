t = int(input())

for i in range(1,t+1):
    a = int(input())
    b = int(input())
    s = 0
    for j in range(a,b+1):
        if j%2!=0:
            s += j
    print('Case {0}: {1}'.format(i,s))

