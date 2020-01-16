vowels = {'a','e','i','o','u','A','E','I','O','U'}

def getSimuno(subj):
    if subj == "I":     return "ko"
    elif subj == "You": return "mo"
    elif subj == "He":  return "niya"
    elif subj == "She": return "niya"
    elif subj == "We":  return "natin"
    elif subj == "They":return "nila"

def getFirstVowel(word):
    firstVowel = -1
    for i in range(len(word)):
        if word[i] in vowels:
            firstVowel = i
            break
    return firstVowel

def getLastVowel(word):
    lastVowel = -1
    for i in range(len(word)):
        if word[i] in vowels:
            lastVowel = i
    return lastVowel

def repeatFirstSyllable(word):
    firstVowel = getFirstVowel(word)
    return word[:firstVowel+1] + word

def lastVowelChange(word):
    lastVowel = getLastVowel(word)
    if word[lastVowel] == 'O':
        word = word[:lastVowel] + 'U' + word[lastVowel+1:]
    elif word[lastVowel] == 'o':
        word = word[:lastVowel] + 'u' + word[lastVowel+1:]
    return word

def addInToEnd(word):
    if word[-1] in vowels:
        return word + 'hin'
    else:
        return word + 'in'

def addInToFirstVowel(word):
    firstVowel = getFirstVowel(word)
    return word[:firstVowel] + 'in' + word[firstVowel:]

def getPandiwa(make, verb):
    pandiwa=verb

    if (make == "will"):
        pandiwa = repeatFirstSyllable(pandiwa)
        pandiwa = lastVowelChange(pandiwa)
        pandiwa = addInToEnd(pandiwa)

    elif (make == "made"):
        pandiwa = addInToFirstVowel(pandiwa)

    elif (make == "make" or make == "makes"):
        pandiwa = repeatFirstSyllable(pandiwa)
        pandiwa = addInToFirstVowel(pandiwa)

    return pandiwa

def capitalize(word):
    return word[0].capitalize() + word[1:]

while(True):
    try: line=input().split()
    except: break
    subj = line[0]
    make = line[1]
    verb = line[2]
    noun = line[4]
    if (make == 'will'):
        verb = line[3]
        noun = line[5]
    
    pandiwa = getPandiwa(make, verb)
    pandiwa = capitalize(pandiwa)
    simuno = getSimuno(subj)

    print(pandiwa, simuno, "ang", noun)

