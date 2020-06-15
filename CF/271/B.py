def genSieve():
    n = 200000
    isPrime = [True for i in range(n)]
    isPrime[0] = isPrime[1] = False
    for i in range(2,n):
        j = i
        while i*j < n:
            isPrime[i*j] = False
            j += 1
    return isPrime

isPrime = genSieve()
def distToPrime(n):
    dist = 0
    while True:
        if isPrime[n+dist]:
            break
        dist += 1
    return dist

def toDistMatrix(matrix):
    n, m = len(matrix), len(matrix[0])
    for i in range(n):
        for j in range(m):
            matrix[i][j] = distToPrime(matrix[i][j])

def getAns(matrix):
    n, m = len(matrix), len(matrix[0])
    ans = 1000000
    for i in range(n):
        temp = 0
        for j in range(m):
            temp += matrix[i][j]
        ans = min(temp, ans)

    for j in range(m):
        temp = 0
        for i in range(n):
            temp += matrix[i][j]
        ans = min(temp, ans)

    return ans

n, m = (int(x) for x in input().split())
matrix = [[int(x) for x in input().split()] for x in range(n)]
toDistMatrix(matrix)
print(getAns(matrix))