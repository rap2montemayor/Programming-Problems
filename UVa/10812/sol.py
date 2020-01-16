t = int(input())

while t>0:
    s,d = [int(x) for x in input().split()]
    a = (s+d)//2
    
    if a-d < 0 or a+a-d != s:
        print('impossible')
    else:
        print(a,a-d)    

    t -= 1
