n = input()
found = False
for digit in n:
    found = found or digit=='7'
if found:
    print("Yes")
else:
    print("No")