#include <iostream>
#include <vector>
using namespace std;

class Solution {
  static int find(vector<int>& group, int i) { return group[i] == i ? i : group[i] = find(group, group[i]); }

public:
  static vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
	vector<int> group(edges.size());
	for (int i = 0; i < group.size(); i++) {
	  group[i] = i;
	}

	for (const auto& edge : edges) {
	  const int u = edge[0] - 1, v = edge[1] - 1;
	  if (find(group, u) == find(group, v)) {
		return edge;
	  }
	  group[find(group, u)] = find(group, v);
	}
	throw logic_error("No solution found");
  }
};

int main() {
  const auto sol = Solution::findRedundantConnection({{1, 2}, {1, 3}, {2, 3}});
  cout << "[" << sol[0] << ", " << sol[1] << "]" << endl;
}