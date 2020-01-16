n,k = [int(x) for x in input().split()]
x = []
y = []
for i in range(n):
    xi,yi = [int(x) for x in input().split()]
    x.append(xi)
    y.append(yi)

ans = (2e9)**2

for i in range(n):
    for j in range(i+1,n):
        area = abs((x[i]-x[j]) * (y[i]-y[j]))
        contains = 0
        for k in range(n):
            if x[k] >= min(x[i],x[j])\
                    and x[k] <= max(x[i],x[j])\
                    and y[k] >= min(y[i],y[j])\
                    and y[k] <= max(y[i],y[j]):
                contains+=1
        if (contains>=k and area<ans):
            ans = area
print(ans)

