ans, n = 1, int(input())
for div in range(2,int(n**0.5*2)):
    if n%div == 0: ans *= div
    while n%div == 0: n //= div
print(ans*n)
