while True:
    n = input()
    if n == '0':
        break
    
    ans = 0
    for i in range(len(n)):
        ans += int(n[len(n)-1-i]) * ((1<<(i+1))-1)
    print(ans)