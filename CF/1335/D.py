for t in range(int(input())):
    sudoku = []
    for i in range(9):
        sudoku.append([int(x) for x in input()])
    
    i = [0,1,2,3,4,5,6,7,8]
    j = [0,3,6,1,4,7,2,5,8]
    for x in range(9):
        for change in range(1,10):
            if sudoku[i[x]][j[x]] != change:
                sudoku[i[x]][j[x]] = change
                break
            
    for line in sudoku:
        print(*(c for c in line),sep='')