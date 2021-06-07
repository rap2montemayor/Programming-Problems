def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)
for _ in range(int(input())):
    print(100 // gcd(int(input()), 100))