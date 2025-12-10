#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  struct dfs_res {
	int components;
	int mod;
	explicit dfs_res(const int components, const int mod) : components(components), mod(mod) {}
  };
  // returns the number of components formed
  static dfs_res dfs(const int at, const int parent, const unordered_map<int, vector<int>>& edges,
                     const vector<int>& values, const int k) {
	int total_components = 0;
	int mod = values[at];
	for (const auto next : edges.at(at)) {
	  if (next == parent)
		continue;
	  const dfs_res child = dfs(next, at, edges, values, k);
	  total_components += child.components;
	  mod += child.mod;
	}
	mod %= k;
	if (mod == 0) {
	  // make a cut
	  total_components++;
	}
	return dfs_res{total_components, mod};
  }

public:
  static int maxKDivisibleComponents(const int n, const vector<vector<int>>& edges, const vector<int>& values,
                                     const int k) {
	unordered_map<int, vector<int>> e;
	for (int i = 0; i < n; i++) {
	  e[i] = vector<int>{};
	}
	for (const auto& edge : edges) {
	  e[edge[0]].push_back(edge[1]);
	  e[edge[1]].push_back(edge[0]);
	}
	const dfs_res res = dfs(0, -1, e, values, k);
	assert(res.mod == 0);
	return res.components;
  }
};

int main() {
  cout << Solution::maxKDivisibleComponents(5, {{0, 2}, {1, 2}, {1, 3}, {2, 4}}, {1, 8, 1, 4, 4}, 6) << endl; // 4
}