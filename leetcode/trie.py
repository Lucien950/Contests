class Trie:
	def __init__(self, val = None):
		self.val = val
		self.children = {}
		self.end = False

	def insert(self, word: str) -> None:
		if len(word) == 0:
			self.end = True
			return
		if word[0] not in self.children:
			self.children[word[0]] = Trie(word[0])
						
		self.children[word[0]].insert(word[1:])
			
	def search(self, word: str) -> bool:
		if len(word) == 0: return self.end == True
		return (self.children[word[0]] != None) and self.children[word[0]].search(word[1:])

	def startsWith(self, prefix: str) -> bool:
		if len(prefix) == 0: return True
		return (self.children[prefix[0]] != None) and self.children[prefix[0]].startsWith(prefix[1:])

obj = Trie()
obj.insert("apple")
param_2 = obj.search("apple")
param_3 = obj.search("app")
param_4 = obj.startsWith("app")

print(param_2, param_3, param_4)