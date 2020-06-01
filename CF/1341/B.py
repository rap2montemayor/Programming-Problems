def findPeaks(a):
    isPeak = [0]*len(a)
    for i in range(1,len(a)-1):
        if a[i] > a[i-1] and a[i] > a[i+1]:
            isPeak[i] = 1
    return isPeak

def toPrefixSum(a):
    prefsum = [0]*len(a)
    prefsum[0] = a[0]
    for i in range(1,len(a)):
        prefsum[i] = a[i]+prefsum[i-1]
    return prefsum

for t in range(int(input())):
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
    isPeak = findPeaks(a)
    peaks = toPrefixSum(isPeak)
    print(isPeak)
    print(peaks)

    parts, l, r = 0, 0, 0
    for i in range(len(peaks)-k):
        count = peaks[i+k-2] - peaks[i+1]

        if count >= parts:
            parts = count
            l = i+1
            r = i+k-2

    print(parts,l,r)
    print()
