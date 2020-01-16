s = input()

stack = []
validtemp = []
validseq = []

stack.append([0,len(s)-1])
for i in range(len(s)):
    if s[i] == '(' or s[i] == '[':
        stack.append([i,-1])

    if s[i] == ')':
        if stack and s[stack[-1][0]] == '(':
            stack[-1][1] = i
            validtemp.append(stack[-1])
            stack.pop()
        else:
            for j in validtemp:
                validseq.append(j)
            stack.clear()
            validtemp.clear()

    if s[i] == ']':
        if stack and s[stack[-1][0]] == '[':
            stack[-1][1] = i
            validtemp.append(stack[-1])
            stack.pop()
        else:
            for j in validtemp:
                validseq.append(j)
            stack.clear()
            validtemp.clear()

    if i == len(s)-1:
        for j in validtemp:
            validseq.append(j)
        if stack and stack[-1] == [0,len(s)-1]:
            validseq.append(stack[-1])

if validseq:
    for i in range(len(validseq)-1):
        if validseq[i+1][0] - validseq[i][1] == 1:
            validseq[i+1][0] = validseq[i][0]

    brackets = []
    ans = 0
    for i in validseq:
        num = 0
        for j in range(i[0], i[1]):
            if s[j] == '[':
                num += 1
        brackets.append(num)
    for i in range(len(brackets)):
        if brackets[i] > brackets[ans]:
            ans = i
        elif brackets[i] == brackets[ans]:
            if validseq[i][1] - validseq[i][0] > validseq[ans][1] - validseq[ans][0]:
                ans = i
    
    print(brackets[ans])
    print(s[validseq[ans][0]:validseq[ans][1]+1])
else:
    print(0)
    print()
