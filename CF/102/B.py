def sumString(s):
    ans = 0
    for c in s:
        ans += int(c)

    return ans

def sumDigits(n):
    ans = 0
    while n > 0:
        ans += n%10
        n //= 10

    return ans

ans = 0
n = input()
if len(n) > 1:
    n = sumString(n)
    ans = 1
    while n >= 10:
        n = sumDigits(n)
        ans += 1

print(ans)
