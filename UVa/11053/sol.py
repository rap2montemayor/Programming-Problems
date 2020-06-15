n, a, b = 0, 0, 0
def nxt(x):
    return (a*x*x + b) % n

def cycleLength():
    p1, p2 = nxt(0), nxt(nxt(0))
    while p1 != p2:
        p1, p2 = nxt(p1), nxt(nxt(p2))

    p2 = nxt(p1)
    length = 1
    while p1 != p2:
        p2 = nxt(p2)
        length += 1

    return length

while True:
    try:
        n, a, b = (int(x) for x in input().split())
    except:
        break
    length = cycleLength()
    print(n-length)
