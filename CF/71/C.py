def getPrimes(n):
    primes = []
    if n % 4 == 0:
        primes.append(4)
    while n % 2 == 0:
        n //= 2

    div = 3
    while n > 1:
        if n % div == 0:
            primes.append(div)
        while n % div == 0:
            n //= div

        div += 1
    
    return primes

def islucky(n, knights, primes):
    lucky = False
    for p in primes:
        if lucky: break

        skip = n // p
        for start in range(skip):
            allLucky = True
            for side in range(p):
                idx = start + side*skip
                if knights[idx] == 0:
                    allLucky = False
                    break
            
            if allLucky:
                lucky = True
                break
    return lucky

n = int(input())
knights = [int(x) for x in input().split()]
primes = getPrimes(n)

if islucky(n, knights, primes):
    print('YES')
else:
    print('NO')


