def findback(fronts, backs):
    count = dict()
    nums = fronts + backs
    for i in nums:
        if i not in count:
            count[i] = 1
        else:
            count[i] += 1
    
    res = -1
    for i in nums:
        if count[i] == 1 and i in backs:
            res = i
            break
    return res

n = int(input())
forward = [-1 for _ in range(int(1e6+1))]
backward = [-1 for _ in range(int(1e6+1))]

fronts = []
backs = []
for _ in range(n):
    front, back = (int(x) for x in input().split())
    forward[front] = back
    backward[back] = front

    fronts.append(front)
    backs.append(back)

ans = [None for i in range(n)]
idx = forward[0]
i = 1
while i < n:
    ans[i] = idx
    i += 2
    idx = forward[idx]

if n%2 == 1:
    idx = findback(fronts, backs)
    i = n-1
else:
    idx = backward[0]
    i = n-2

while i >= 0:
    ans[i] = idx
    i -= 2
    idx = backward[idx]

print(*(i for i in ans))
