#include <cassert>
#include <stack>
#include <stdexcept>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  static TreeNode* constructFromPrePost(const vector<int>& preorder, const vector<int>& postorder) {
	stack<TreeNode*> s;
	s.push(new TreeNode(preorder[0]));
	TreeNode* root = s.top();

	auto postorder_at = postorder.begin();
	for (int i = 1; i < preorder.size(); ++i) {
	  if (TreeNode* at = s.top(); at->left == nullptr) {
		at->left = new TreeNode(preorder[i]);
		s.push(at->left);
	  } else if (at->right == nullptr) {
		at->right = new TreeNode(preorder[i]);
		s.push(at->right);
	  } else {
		throw logic_error("Invalid input");
	  }
	  for (; postorder_at < postorder.end() && *postorder_at == s.top()->val; ++postorder_at) {
		s.pop();
	  }
	}
	assert(preorder.size() == 1 || s.empty());
	assert(postorder_at == postorder.end());
	return root;
  }
};

int main() { Solution::constructFromPrePost({1, 2, 4, 5, 3, 6, 7}, {4, 5, 2, 6, 7, 3, 1}); }