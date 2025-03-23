#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  static bool is_bipartite(const int n, const map<int, vector<int>>& adj, vector<vector<int>>& components) {
	vector<int8_t> color(n + 1, -1);
	for (int start = 1; start <= n; start++) {
	  if (color[start] != -1)
		continue;
	  components.emplace_back();
	  if (!adj.contains(start))
		continue;
	  queue<int> toExplore;
	  toExplore.push(start);
	  color[start] = 0;
	  components.back().push_back(start);
	  while (!toExplore.empty()) {
		int at = toExplore.front();
		toExplore.pop();
		for (const auto& next : adj.at(at)) {
		  if (color[next] != -1) { // ie explored
			if (color[next] == color[at])
			  return false;
			continue;
		  }
		  toExplore.push(next);
		  color[next] = 1 - color[at];
		  components.back().push_back(next);
		}
	  }
	}
	return true;
  }

  static pair<int, int> getFurthestNode(const int start, const int n, const map<int, vector<int>>& adj) {
	queue<int> toExplore;
	vector distance(n + 1, -1);
	toExplore.push(start);
	distance[start] = 0;

	// int best_node = -1, best_distance = -1;
	while (!toExplore.empty()) {
	  const int at = toExplore.front();
	  toExplore.pop();
	  for (const int next : adj.at(at)) {
		if (distance[next] != -1)
		  continue;
		toExplore.push(next);
		distance[next] = distance[at] + 1;
	  }
	}
	pair out = {-1, -1};
	for (int i = 1; i <= n; i++)
	  if (distance[i] > out.second) {
		out.first = i;
		out.second = distance[i];
	  }
	return out;
  }

public:
  static int magnificentSets(const int n, const vector<vector<int>>& edges) {
	map<int, vector<int>> adj;
	for (const auto& edge : edges) {
	  adj[edge[0]].push_back(edge[1]);
	  adj[edge[1]].push_back(edge[0]);
	}

	vector<vector<int>> components;
	if (!is_bipartite(n, adj, components))
	  return -1;

	int out = 0;
	for (auto& component : components) {
	  if (component.empty()) {
		out += 1;
		continue;
	  }
	  int furthest_distance = 0;
	  for (const int start : component) {
		const auto& [_a, distance] = getFurthestNode(start, n, adj);
		furthest_distance = max(furthest_distance, distance);
	  }
	  out += furthest_distance + 1;
	}
	return out;
  }
};

int main() {
  cout << Solution::magnificentSets(
              26, {{9, 16},  {8, 3},   {20, 21}, {12, 16}, {14, 3},  {7, 21},  {22, 3},  {22, 18}, {11, 16}, {25, 4},
                   {2, 4},   {14, 21}, {23, 3},  {17, 3},  {2, 16},  {24, 16}, {13, 4},  {10, 21}, {7, 4},   {9, 18},
                   {14, 18}, {14, 4},  {14, 16}, {1, 3},   {25, 18}, {17, 4},  {1, 16},  {23, 4},  {2, 21},  {5, 16},
                   {24, 18}, {20, 18}, {19, 16}, {24, 21}, {9, 3},   {24, 3},  {19, 18}, {25, 16}, {19, 21}, {6, 3},
                   {26, 18}, {5, 21},  {20, 16}, {2, 3},   {10, 18}, {26, 16}, {8, 4},   {11, 21}, {23, 16}, {13, 16},
                   {25, 3},  {7, 18},  {19, 3},  {20, 4},  {26, 3},  {23, 18}, {15, 18}, {17, 18}, {10, 16}, {26, 21},
                   {23, 21}, {7, 16},  {8, 18},  {10, 4},  {24, 4},  {7, 3},   {11, 18}, {9, 4},   {26, 4},  {13, 21},
                   {22, 16}, {22, 21}, {20, 3},  {6, 18},  {9, 21},  {10, 3},  {22, 4},  {1, 18},  {25, 21}, {11, 4},
                   {1, 21},  {15, 3},  {1, 4},   {15, 16}, {2, 18},  {13, 3},  {8, 21},  {13, 18}, {11, 3},  {15, 21},
                   {8, 16},  {17, 16}, {15, 4},  {12, 3},  {6, 4},   {17, 21}, {5, 18},  {6, 16},  {6, 21},  {12, 4},
                   {19, 4},  {5, 3},   {12, 21}, {5, 4}})
       << endl;
}