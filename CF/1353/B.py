for t in range(int(input())):
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    a.sort()
    b.sort(reverse=True)

    aptr, bptr = 0, 0
    swaps = 0
    while swaps < k:
        if aptr >= n or bptr >= n: break
        if a[aptr] < b[bptr]:
            swaps += 1
            a[aptr], b[bptr] = b[bptr], a[aptr]
        aptr += 1
        bptr += 1

    print(sum(a))