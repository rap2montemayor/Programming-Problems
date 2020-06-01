sides = [int(x) for x in input().split()]
bigtriangle = (sides[0] + sides[1] + sides[2]) ** 2
ans = bigtriangle - sides[0]**2 - sides[2]**2 - sides[4]**2
print(ans)
