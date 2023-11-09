from typing import List

from collections import defaultdict

class TrieNode:
	def __init__(self, value: str, isEnd:bool):
		self.value = value
		self.isEnd = isEnd
		self.children: dict[str, TrieNode] = {}
		
class Trie:
	def __init__(self, arr: List[str]):
		self.root = TrieNode("", False)
		self.head = self.root
		for word in arr:
			self.addWord(self.root, word)
	# building trie
	def addWord(self, loc: TrieNode, word: str):
		if len(word) == 0:
			loc.isEnd = True
			return
		if word[0] not in loc.children:
			nextTrieNode = TrieNode(word[0], False)
			loc.children[word[0]] = nextTrieNode
		else:
			nextTrieNode = loc.children[word[0]]
		self.addWord(nextTrieNode, word[1:])
	# navigation on search
	def isHeadEnd(self) -> bool:
		return self.head.isEnd
	def navigateHead(self, next: str):
		try:
			self.head = self.root.children[next]
			return True
		except IndexError:
			return False
	def resetHead(self):
		self.head = self.root
	
class Solution:
	def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
		forbiddenTrie = Trie(forbidden)
		maxWordSize = 0
		for l in range(0, len(word) - 1): # right inclusive
			for wordSize in range(1, 11):
				r = l + wordSize
				if r > len(word) - 1: break # out of bounds
				validSpot = forbiddenTrie.navigateHead(word[r])
				if not validSpot: break
				if forbiddenTrie.isHeadEnd():
					maxWordSize = max(maxWordSize, wordSize)
			forbiddenTrie.resetHead()
		return maxWordSize