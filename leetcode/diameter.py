from typing import List, Optional

class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

class Solution:
	res = 0
	def maxDepth(self, root: Optional[TreeNode]) -> int:
		if root == None: return 0
		lmd, rmd = self.maxDepth(root.left), self.maxDepth(root.right)
		self.res = max(self.res, lmd + rmd)
		return max(lmd, rmd) + 1
	def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
		if root == None: return 0

		maxDepth = self.maxDepth(root)
		# print(maxDepth)
		return self.res

btree = TreeNode(val=1,left=TreeNode(val=2, left=TreeNode(val=4), right=TreeNode(val=5)), right=TreeNode(val=3))
print(Solution().diameterOfBinaryTree(btree))