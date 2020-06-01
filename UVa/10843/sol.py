for n in range(1,int(input())+1):
    x = int(input())
    ans = 1 if x==0 else int(x**(x-2))
    print(f'Case #{n}: {ans%2000000011}')
