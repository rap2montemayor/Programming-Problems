conditions = []

def getConditions():
    c1 = input()
    c2 = input()
    c3 = input()
    conditions.append(c1)
    conditions.append(c2)
    conditions.append(c3)

def evalConditions(A,B,C):
    letter = {'A':0, 'B':1, 'C':2}
    coins = (A, B, C)

    allTrue = True
    for s in conditions:
        left = coins[letter[s[0]]]
        right = coins[letter[s[2]]]
        op = s[1]
        
        if op == '>':
            allTrue = allTrue and left > right
        else:
            allTrue = allTrue and left < right

    return allTrue

def getOrdering():
    for A in range(3):
        for B in range(3):
            for C in range(3):
                if evalConditions(A, B, C):
                    return (A, B, C)

    return (-1, -1, -1)


def printOrder(A, B, C):
    cur = 0
    out = ''
    while cur < 3:
        if A == cur:
            out += 'A'
        if B == cur:
            out += 'B'
        if C == cur:
            out += 'C'
        cur += 1

    if len(out) < 3:
        print('Impossible')
    else:
        print(out)

getConditions()
A, B, C = getOrdering()
printOrder(A, B, C)
