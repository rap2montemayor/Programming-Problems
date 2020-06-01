for t in range(int(input())):
    n = int(input())
    s = [int(x) for x in input().split()]
    s.sort()
    ans = 104206969
    for i in range(1,len(s)):
        ans = min(ans, abs(s[i]-s[i-1]))
    print(ans)