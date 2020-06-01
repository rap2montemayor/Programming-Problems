x, y = (int(x) for x in input().split())
n = int(input()) - 1
pattern = [x, y, y-x, -x, -y, x-y]
print(pattern[n % 6] % int(1e9+7))