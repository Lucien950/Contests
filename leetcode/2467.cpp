#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  static int bob_dfs(const int at, const int depth, const vector<vector<int>>& adj, vector<int>& from) {
	if (at == 0)
	  return depth;
	int longest_path = -1;
	for (const int next : adj[at]) {
	  if (from[next] != -1)
		continue;
	  from[next] = at;
	  longest_path = max(longest_path, bob_dfs(next, depth + 1, adj, from));
	}
	return longest_path;
  }

  static int alice_dfs(const int at, const int cur_cost, vector<bool>& explored, const vector<vector<int>>& adj,
                       const vector<int>& amounts) {
	explored[at] = true;
	bool is_leaf = true;
	int out = INT_MIN;
	for (const int n : adj[at]) {
	  if (explored[n])
		continue;
	  out = max(out, alice_dfs(n, cur_cost + amounts[n], explored, adj, amounts));
	  is_leaf = false;
	}
	if (is_leaf)
	  return cur_cost;
	else
	  return out;
  }

public:
  static int mostProfitablePath(const vector<vector<int>>& edges, const int bob, vector<int>& amount) {
	vector<vector<int>> adj(amount.size());
	for (const vector<int>& edge : edges) {
	  adj[edge[0]].push_back(edge[1]);
	  adj[edge[1]].push_back(edge[0]);
	}
	// nav bob from bob to 0
	{
	  vector from(amount.size(), -1);
	  from[bob] = -2;
	  const int path_length = bob_dfs(bob, 0, adj, from) + 1;
	  // keep track of exact halfway point, if exists, half it
	  int backtrack_at = 0;
	  for (int i = 0; i < path_length / 2 - 1; ++i) {
		backtrack_at = from[backtrack_at];
	  }
	  if (path_length % 2 == 1) {
		backtrack_at = from[backtrack_at];
		amount[backtrack_at] /= 2;
	  }
	  for (int i = 0; i < path_length / 2; ++i) {
		backtrack_at = from[backtrack_at];
		amount[backtrack_at] = 0;
	  }
	}

	// bfs alice from 0 to all leaves
	vector explored(amount.size(), false);
	return alice_dfs(0, amount[0], explored, adj, amount);
  }
};

int main() {
  vector amount = {-6896, -1216, -1208, -1108, 1606, -7704, -9212, -8258};
  cout << Solution::mostProfitablePath({{0, 2}, {1, 4}, {1, 6}, {2, 4}, {3, 6}, {3, 7}, {5, 7}}, 4, amount) << endl;
}