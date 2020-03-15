def digitalSum(n,b):
    res=0
    while n>0:
        res += n%b
        n//=b
    return res

def digitalRoot(n,b):
    while n>b-1:
        n = digitalSum(n,b)
    return n

b = 10
for k in range(1,50): 
    print(b,k)
    for i in range(0,b):
        print(digitalRoot(i*k,b),end=' ')
    print("\n")
    
