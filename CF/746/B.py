n = int(input())
s = input()
ans = ''

if n%2 == 1:
    for i in range(n):
        if i%2 == 0:
            ans = ans + s[i]
        else:
            ans = s[i] + ans
else:
    for i in range(n):
        if i%2 == 1:
            ans = ans + s[i]
        else:
            ans = s[i] + ans

print(ans)
