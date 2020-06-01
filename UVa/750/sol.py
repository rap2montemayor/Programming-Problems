configs = []

def isValid(board, i, j):
    di = [1, 1, 0, -1, -1, -1, 0, 1]
    dj = [0, 1, 1, 1, 0, -1, -1, -1]
    for m in range(1,8):
        for x in range(8):
            ii = i + di[x]*m
            jj = j + dj[x]*m
            validCoord = 0 <= ii < 8 and 0 <= jj < 8
            if validCoord and board[ii][jj] == 1:
                return False
    return True

def gen8queens(board, row):
    if row == 8:
        pos = [0 for i in range(8)]
        for j in range(8):
            for i in range(8):
                if board[i][j] == 1:
                    pos[j] = i
        configs.append(pos)
        return
    
    for col in range(8):
        board[row][col] = 1
        if isValid(board, row, col):
            gen8queens(board, row+1)
        board[row][col] = 0

board = [[0 for x in range(8)] for x in range(8)]
gen8queens(board, 0)

t = int(input())
input()

for T in range(t):
    pos = [-1 for _ in range(8)]
    ans = []
    while True:
        try:
            x, y = (int(x) for x in input().split())
            x, y = x-1, y-1
            pos[y] = x
        except: break

    for config in configs:
        match = True
        for i in range(8):
            if pos[i] == -1: continue
            if pos[i] != config[i]:
                match = False
                break
        if match:
            ans.append(config)

    ans.sort()
    print('SOLN       COLUMN')
    print(' #      1 2 3 4 5 6 7 8\n')
    for i in range(len(ans)):
        if i+1 <= 9:
            print(' ', end='')
        print('{0}      '.format(i+1), end='')
        print(*(x+1 for x in ans[i]))
    if T < t-1:
        print()