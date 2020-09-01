class Tree(object):
	
	def __init__(self, root, left=None, right=None):
		assert root and type(root) == Node
		if left: assert type(left) == Tree and left.root < root
		if right: assert type(right) == Tree and root < right.root
		
		self.left = left
		self.root = root
		self.right = right
	
	def is_leaves(self):
		return not (self.left or self.right)
	
	def get_children(self):
		return [self.left, self.root, self.right]
	
	def __str__(self):
		if self.is_leaves():
			return "[" + str(self.root) + ":" + str(self.root.weight) + "]"
		
		return ("[" +
				(str(self.left) if self.left else "_") +
				" " +
				str(self.root) + ":" + str(self.root.weight) +
				" " +
				(str(self.right) if self.right else "_") +
				"]"
			)
	
	def __eq__(self, other):  # Check equals
		if str(self) == str(other):
			return True
		return False
	
	def __ne__(self, other):  # Check not equals
		if self == other:
			return False
		return True
class Node(object):
	
	def __init__(self, value, weight=1):
		self.value = value
		self.weight = weight
	
	def __str__(self):
		return str(self.value)
	
	def __lt__(self, other):
		return self.value < other.value
	
	def __gt__(self, other):
		return self.value > other.value
	
	def __eq__(self, other):
		return self.value == other.value
	
	def __ne__(self, other):
		return self.value != other.value


def cost(tree, depth=1):
	left, mid, right = tree.get_children()
	return ((cost(left, depth + 1) if left else 0) +
			mid.weight*depth +
			(cost(right, depth + 1) if right else 0)
	)


def make_min_tree(node_list):
	node_list = sorted(node_list, key=lambda node: node.weight)
	
	
	print([(str(node) + ":" + str(node.weight)) for node in node_list])
	return Tree(node_list.pop())
	











#Activation Code
a = Node('A', 10)
b = Node('B', 2)
c = Node('C', 4)
d = Node('D', 9)
e = Node('E', 8)

tree_a = Tree(a)
#[[A:10] B:2 _]
tree_ab1 = Tree(b, Tree(a), None)



tree5 = make_min_tree([a, b, c, d, e])
print(tree5)

tree = Tree(a, right = Tree(c, left = b))
print(tree)