def isAnagram(s: str, t: str):
	f1 = [0] * 26
	f2 = [0] * 26
	for c in s:
		i = ord(c)-97
		f1[i] += 1
	for c in t:
		i = ord(c)-97
		f2[i] += 1
	return f1 == f2

isAnagram("anagram", "nagaram")