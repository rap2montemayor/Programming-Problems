n,m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
rem = {}
rem[0]=1
sum=0
ans=0
for i in a:
    sum+=i
    if (sum%m in rem): rem[sum%m] += 1
    else: rem[sum%m] = 1
    ans += rem[sum%m]-1
print(ans)
