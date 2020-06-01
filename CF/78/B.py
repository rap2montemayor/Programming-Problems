n = int(input())

while n >= 7:
    n -= 7
    print("ROYGBIV",end='')
if n <= 3:
    print("GBI"[:n])
else:
    print("ROYGBIV"[:n])
