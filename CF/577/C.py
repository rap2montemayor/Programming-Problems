n = int(input())

isprime = [True for i in range(n+1)]
for i in range(2, len(isprime)):
    j = i
    while i*j < len(isprime):
        isprime[i*j] = False
        j += 1

# powers of primes
ans = []
for i in range(2, len(isprime)):
    if isprime[i]:
        j = 1
        while i*j <= n:
            ans.append(i*j)
            j *= i
print(len(ans))
print(*(x for x in ans))
