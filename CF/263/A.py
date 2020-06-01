matrix = []
for i in range(5):
    matrix.append(input().split())

i = -1
j = -1
for x in range(5):
    for y in range(5):
        if matrix[x][y]=='1':
            i = x
            j = y

print(abs(i-2) + abs(j-2))
