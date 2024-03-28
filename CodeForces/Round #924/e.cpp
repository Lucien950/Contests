#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct furthestNodePathDistance {
  int node;
  vector<int> path;
  int distance;
};
furthestNodePathDistance getFurthestNode(const int at, const vector<vector<int>>& adj, vector<bool>& explored) {
  int furthestNode = at, furthestDistance = 0;
  vector<int> longestPath;
  explored.assign(at, true);
  for (const auto node : adj[at]) {
	if (const auto [n, path, dist] = getFurthestNode(node, adj, explored); dist > furthestDistance) {
	  furthestNode = n;
	  furthestDistance = dist;
	  longestPath = path;
	}
  }
  longestPath.push_back(at);
  return {furthestNode, longestPath, furthestDistance + 1};
}

struct furthestNodePath {
  int node;
  vector<int> path;
};
furthestNodePath getFurthestNode(const int start, const vector<vector<int>>& adj) {
  auto explored = vector(adj.size(), false);
  auto [node, path, distance] = getFurthestNode(start, adj, explored);
  std::reverse(path.begin(), path.end());
  return {node, path};
}

int main() {
  int t;
  cin >> t; // t < 200
  while (t--) {
	int vertexCount;
	cin >> vertexCount; // vertexCount < 2000

	vector<vector<int>> adj(vertexCount + 1);
	for (int edge_index = 0; edge_index < vertexCount - 1; edge_index++) {
	  int u, v;
	  cin >> u >> v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	}

	if (vertexCount == 1) {
	  cout << 1 << endl;
	  continue;
	}

	const auto [diameterNode1, _p] = getFurthestNode(1, adj);
	const auto [_diameterNode2, diameterPath] = getFurthestNode(diameterNode1, adj);

	// get midpoint of diameterPath
	const size_t diameterPathSize = diameterPath.size();
	const int center = diameterPath.at(diameterPathSize / 2), afterCenter = diameterPath.at(diameterPathSize / 2 + 1);
	for (size_t d = 1; d <= diameterPathSize / 2; d++) {
	  cout << center << " " << d;
	}
	cout << afterCenter << " " << 1 << endl;
  }
}