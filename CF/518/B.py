s, t = input(), input()

count = dict()
for c in t + s:
    count[c.upper()] = 0
    count[c.lower()] = 0

for c in t:
    count[c] += 1
    
yay, woops = 0, 0
temp = ''
for c in s:
    if count[c] > 0:
        yay += 1
        count[c] -= 1
    else:
        temp += c

for c in temp:
    if c == c.upper() and count[c.lower()] > 0:
        woops += 1
        count[c.lower()] -= 1
    elif c == c.lower() and count[c.upper()] > 0:
        woops += 1
        count[c.upper()] -= 1

print(yay, woops)