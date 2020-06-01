for t in range(int(input())):
    n = int(input())

    pow2 = 4
    while n % (pow2 - 1) != 0:
        pow2 *= 2
    print(n // (pow2-1))
