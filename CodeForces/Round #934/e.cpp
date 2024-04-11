#include <algorithm>
#include <iostream>
#include <stdint.h>
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
  explored[at] = true;
  for (const auto node : adj[at]) {
	if (explored[node])
	  continue;
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
  auto explored = vector(adj.size() + 1, false);
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
	  cout << 1 << " " << 0 << endl;
	  continue;
	}

	const auto [diameterNode1, _p] = getFurthestNode(1, adj);
	const auto [_diameterNode2, diameterPath] = getFurthestNode(diameterNode1, adj);

	// get midpoint of diameterPath
	const size_t diameterPathSize = diameterPath.size();
	const int center = diameterPath.at(diameterPathSize / 2), beforeCenter = diameterPath.at(diameterPathSize / 2 - 1);

	vector<pair<int, int>> out;
	if (diameterPathSize % 2 == 0) {
	  for (int64_t d = (int64_t)diameterPathSize / 2 - 1; d >= 0; d -= 2) {
		out.emplace_back(center, d);
		out.emplace_back(beforeCenter, d);
	  }
	} else { // odd case
	  for (size_t d = 0; d <= diameterPathSize / 2; d++) {
		out.emplace_back(center, d);
	  }
	}

	cout << out.size() << endl;
	for (pair<int, int> p : out) {
	  cout << p.first << " " << p.second << endl;
	}
  }
}