def getLastMatch(s,t):
    for i in range(len(s)-len(t), -1, -1):
        if s[i] == '?' or s[i] == t[0]:
            match = True
            for j in range(len(t)):
                if s[i+j] == '?': continue
                if s[i+j] != t[j]:
                    match = False
                    break
            if match: return i
    return -1
 
def getS(s,t,lastMatch):
    s = list(s)
    for i in range(len(t)):
        s[i+lastMatch] = t[i]
    for i in range(len(s)):
        if s[i]=='?': s[i] = 'a'
    res = ''
    for c in s: res+=c
    return res
 
 
s,t = input(), input()
lastMatch = getLastMatch(s,t)
if lastMatch == -1:
    print('UNRESTORABLE')
else:
    print(getS(s,t,lastMatch))
