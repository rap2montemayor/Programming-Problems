def hasIntersection(range1, range2):
    lower1, upper1 = range1[0], range1[1]
    lower2, upper2 = range2[0], range2[1]

    c1 = lower2 <= lower1 <= upper2
    c2 = lower2 <= upper1 <= upper2
    c3 = lower1 <= lower2 <= upper1
    c4 = lower1 <= upper2 <= upper1

    return c1 or c2 or c3 or c4


for t in range(int(input())):
    n,a,b,c,d = (int(x) for x in input().split())

    lower, upper = (a-b)*n, (a+b)*n
    if hasIntersection((lower,upper), (c-d,c+d)):
        print("Yes")
    else:
        print("No")