#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  static int find(const int node, vector<int>& parent) {
	if (node == parent[node])
	  return node;
	return parent[node] = find(parent[node], parent);
  }

public:
  static int countCompleteComponents(const int n, const vector<vector<int>>& edges) {
	// do disjoint set
	vector<int> parent(n);
	for (int i = 0; i < n; i++) {
	  parent[i] = i;
	}

	unordered_map<int, int> connection_count; // mapping nodes to how many other nodes they are connected to
	for (const vector<int>& edge : edges) {
	  const int u = edge[0], v = edge[1];
	  // i think if u, v are not present, this should init them to 0
	  connection_count[u]++;
	  connection_count[v]++;
	  if (const int pv = find(v, parent), pu = find(u, parent); pu != pv) {
		parent[pu] = pv;
	  }
	}

	// first we assume that this set is empty
	unordered_map<int, int> nodes_in_component;
	int num_connected_components = 0;

	for (int node = 0; node < n; node++) {
	  if (node == parent[node]) {
		num_connected_components++;
	  }
	  nodes_in_component[find(node, parent)]++;
	}

	// for each connected component, find if it is complete
	// in particular, iterate through each point and find that it is connected to at least each other point
	set<int> noncomplete_connected_components;
	for (int node = 0; node < n; node++) {
	  if (node == parent[node]) {
		num_connected_components++;
	  }

	  // very subtle reason this works
	  // we assume that the parent[node] is fully connected.
	  if (connection_count[node] != connection_count[parent[node]]) {
		noncomplete_connected_components.insert(parent[node]);
	  }
	}

	return out;
  }
};

int main() { return Solution::countCompleteComponents(5, {{0, 1}, {1, 2}, {3, 4}}); }