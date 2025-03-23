#include <array>
#include <string>
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
  struct info {
	int depth = 0;
	int val = 0;
	int char_incr = 0;
  };

  static info parse_info(const string& traversal, int traversal_i) {
	info out_info;
	const int original_traversal_i = traversal_i;
	for (; traversal[traversal_i] == '-'; ++out_info.depth, traversal_i++)
	  ;
	for (; traversal[traversal_i] != '-' && traversal_i < traversal.size(); ++traversal_i) {
	  out_info.val = out_info.val * 10 + traversal[traversal_i] - '0';
	}
	out_info.char_incr = traversal_i - original_traversal_i;
	return out_info;
  }

  static TreeNode* build_children(const int n_val, const string& traversal, int& traversal_i, const int at_depth) {
	const auto at = new TreeNode(n_val);
	// in case you are the last node in the string
	for (TreeNode** child : std::array<TreeNode**, 2>{{&at->left, &at->right}}) {
	  if (traversal_i >= traversal.size())
		break;
	  if (auto [child_depth, child_val, child_incr] = parse_info(traversal, traversal_i); child_depth > at_depth) {
		traversal_i += child_incr;
		*child = build_children(child_val, traversal, traversal_i, at_depth + 1);
	  } else {
		return at;
	  }
	}
	return at;
  }

public:
  static TreeNode* recoverFromPreorder(const string& traversal) {
	auto [child_depth, child_val, child_incr] = parse_info(traversal, 0);
	return build_children(child_val, traversal, child_incr, child_depth);
  }
};

int main() { delete Solution::recoverFromPreorder("1-401--349---90--88"); }