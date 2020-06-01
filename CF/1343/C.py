def getNegativeSegments(a):
    negSegments = set()
    start, end = 0, 0
    insegment = False
    for i in range(len(a)):
        if a[i] < 0 and insegment == False:
            insegment = True
            start = i
        if a[i] > 0  and insegment == True:
            insegment = False
            end = i
            negSegments.add((start,end))
    if insegment == True:
        negSegments.add((start,len(a)))

    return negSegments

def getPositiveSegments(a):
    posSegments = set()
    start, end = 0, 0
    insegment = False
    for i in range(len(a)):
        if a[i] > 0 and insegment == False:
            insegment = True
            start = i
        if a[i] < 0  and insegment == True:
            insegment = False
            end = i
            posSegments.add((start,end))
    if insegment == True:
        posSegments.add((start,len(a)))
        
    return posSegments

for t in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    negSegments = getNegativeSegments(a)
    posSegments = getPositiveSegments(a)

    ans = 0
    for seg in negSegments:
        ans += max(a[seg[0]:seg[1]])

    for seg in posSegments:
        ans += max(a[seg[0]:seg[1]])

    print(ans)