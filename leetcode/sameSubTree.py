from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
	def sameTree(self, treeA, treeB):
		if treeA == treeB == None: return True
		if (treeA == None and treeB != None) or (treeA != None and treeB == None): return False
		matchRight = self.sameTree(treeA.right, treeB.right)
		matchLeft = self.sameTree(treeA.left, treeB.left)
		return (treeA.val == treeB.val) and matchLeft and matchRight
	def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
		if root == None: return False
		if self.sameTree(root, subRoot): return True
		return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
	

subroot = TreeNode(val=4, left=TreeNode(val=1), right=TreeNode(val=2))
btree = TreeNode(val=3, left=subroot, right=TreeNode(val=5))
print(Solution().isSubtree(btree, subroot))