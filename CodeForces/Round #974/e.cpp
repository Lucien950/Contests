#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct node_weight {
  int node;
  int weight;
};

int main() {
  int t;
  cin >> t;
  while (t--) {
	int v_count, e_count, horse_count;
	std::vector has_horse(v_count, false);
	std::unordered_map<int, std::vector<node_weight>> neighbours;

	cin >> v_count >> e_count >> horse_count;
	for (int i = 0; i < horse_count; i++) {
	  int horse;
	  cin >> horse;
	  has_horse[horse] = true;
	}
	for (int i = 0; i < e_count; i++) {
	  int u, v, w;
	  cin >> u >> v >> w;
	  neighbours[u].push_back({v, w});
	  neighbours[v].push_back({u, w});
	}

	std::vector travel_time_marian(v_count, -1);
	std::queue < struct {
	  int node;
	  int weight;
	  bool horse;
	} > to_explore;
	std::vector explored(v_count, false);
	to_explore.push({1, 0, false});
	while (!to_explore.empty()) {
	  const auto at = to_explore.front();
	  to_explore.pop();
	  travel_time_marian[at.node] = at.weight;
	  const bool has_horse_now = at.horse || has_horse[at.node];
	  for (const auto& n : neighbours.at(at.node)) {
		if (explored[n.node])
		  continue;
		to_explore.push({n.node, at.weight + n.weight / (has_horse_now ? 2 : 1), has_horse_now});
		explored[n.node] = true;
	  }
	}

	// travel_time_marian is populated now
	if (travel_time_marian[v_count - 1] == -1) {
	  cout << -1 << endl;
	}
  }
}