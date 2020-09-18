def countremove(n, mod):
	res = 0
	for i in range(len(n)):
		if mod[len(n)-1-i] == 3:
			continue
		if n[i] == '0':
			res += 1
		else:
			break
	return res

def markremove(n):
	mod = [int(x)%3 for x in n][::-1]
	excess = sum(mod) % 3
	ones = mod.count(1)
	twos = mod.count(2)

	if excess == 1:
		remove1, remove2 = 104206969, 104206969
		if ones > 0:
			mod[mod.index(1)] = 3
			remove1 = countremove(n, mod) + 1
			mod[mod.index(3)] = 1

		if twos > 1:
			mod[mod.index(2)] = 3
			mod[mod.index(2)] = 3
			remove2 = countremove(n, mod) + 2
			mod[mod.index(3)] = 2
			mod[mod.index(3)] = 2

		if remove1 < remove2:
			mod[mod.index(1)] = 3
		else:
			mod[mod.index(2)] = 3
			mod[mod.index(2)] = 3
	elif excess == 2:
		remove1, remove2 = 104206969, 104206969
		if twos > 0:
			mod[mod.index(2)] = 3
			remove1 = countremove(n, mod) + 1
			mod[mod.index(3)] = 2

		if ones > 1:
			mod[mod.index(1)] = 3
			mod[mod.index(1)] = 3
			remove2 = countremove(n, mod) + 2
			mod[mod.index(3)] = 1
			mod[mod.index(3)] = 1

		if remove1 < remove2:
			mod[mod.index(2)] = 3
		else:
			mod[mod.index(1)] = 3
			mod[mod.index(1)] = 3
	return mod

def buildans(n, mod):
	excess = sum(mod) % 3
	ans = ''
	for i in range(len(n)-1, -1, -1):
		if mod[i] != 3: ans += n[len(n)-1-i]

	remove0s = 0
	for i in range(len(ans)):
		remove0s = i
		if ans[i] != '0':
			break
	if remove0s > 0:
		ans = ans[remove0s:]

	if excess != 0 or ans == '':
		ans = '-1'
	return ans
	
n = input()
mod = markremove(n)
print(buildans(n, mod))

