#include <iostream>
#include <vector>

using namespace std;

struct res {
  int child_count;   // counts the amount of connected children
  int subtree_count; // counts the amount of trees that have been cut off
};

res dfs(const int at, const int min_size, const vector<vector<int>>& adj, vector<bool>& explored) {
  res out = {0, 0};
  explored[at] = true;
  for (const int child : adj[at]) {
	if (explored[child])
	  continue;
	const res subResult = dfs(child, min_size, adj, explored);
	out.subtree_count += subResult.subtree_count; // ez carryover
	// decide if we make the children a new subtree or not
	if (subResult.child_count >= min_size)
	  out.subtree_count++;
	else
	  out.child_count += subResult.child_count;
  }
  out.child_count++;
  return out;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int vCount, minRmEdgesCount;
	cin >> vCount >> minRmEdgesCount;

	// build adj matrix
	vector<vector<int>> adj;
	adj.resize(vCount + 1);
	for (int i = 0; i < vCount - 1; i++) {
	  int u, v;
	  cin >> u >> v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	}

	// bsearch on the size of tree groups
	int l = 1, r = vCount / (minRmEdgesCount + 1);
	while (l <= r) {
	  const int try_size = (l + r) / 2;
	  vector explored(vCount + 1, false);
	  const res dfs_res = dfs(1, try_size, adj, explored);
	  const int total_subtree_count = dfs_res.subtree_count + (dfs_res.child_count >= try_size ? 1 : 0);
	  if (const int rmEdgeCount = total_subtree_count - 1; rmEdgeCount >= minRmEdgesCount) {
		l = try_size + 1;
	  } else {
		r = try_size - 1;
	  }
	}
	cout << r << endl;
  }
}