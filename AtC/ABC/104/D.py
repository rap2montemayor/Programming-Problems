s = input()
ABC = [0 for c in s]
AB = [0 for c in s]
A = [0 for c in s]
qmarks=0
if s[0]=='A' or s[0]=='?': A[0]=1;

for i in range(0,len(s)):
    mult=1
    if (s[i]=='?'): mult=3
    A[i] = A[i-1]*mult
    AB[i] = AB[i-1]*mult
    ABC[i] = ABC[i-1]*mult

    if s[i]=='A':
        A[i] += + 3**qmarks
    elif s[i] == 'B':
        AB[i] += A[i-1]
    elif s[i] == 'C':
        ABC[i] += AB[i-1]
    else:
        A[i] += 3**qmarks
        AB[i] += A[i-1]
        ABC[i] += AB[i-1]
        qmarks+=1

print(ABC[-1]%(1e9+7))
