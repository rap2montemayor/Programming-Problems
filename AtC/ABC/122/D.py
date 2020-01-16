n = int(input())
dp = [{} for i in range(101)]
disallowed = ["AGC","GAC","ACG","AGGC","AGTC","ATGC"]
s = "ACGT"
#n==3
for a in s:
    for b in s:
        for c in s:
            for d in s:
                res = a+b+c
                if res == "AGC" or res == "GAC" or res == "ACG": continue
                res += d
                if res == "AGGC" or res == "AGTC" or res == "ATGC": continue
                dp[4][res]=1

for i in range(4,100):
    for j in dp[i]

print(dp)
