#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  uint32_t v, e;
  cin >> v >> e;

  struct weight_dest {
	uint32_t dest;
	uint32_t weight;
  };

  unordered_map<uint32_t, vector<weight_dest>> adj;
  for (uint32_t i = 0; i < e; i++) {
	uint32_t a, b, weight;
	cin >> a >> b >> weight;
	adj[a].push_back({b, weight});
	adj[b].push_back({a, weight});
  }

  struct state {
	uint32_t at;
	uint32_t from;
	uint64_t weight_so_far;
	auto operator<=>(const state& other) const { return weight_so_far <=> other.weight_so_far; }
	state(const uint32_t at, const uint32_t from, const uint64_t weight_so_far)
	    : at(at), from(from), weight_so_far(weight_so_far) {}
  };

  priority_queue<state, vector<state>, greater<>> pq;
  unordered_map<uint32_t, uint32_t> from; // from[a] indicates the node that a was reached from
  unordered_map<uint32_t, uint64_t> best; // best[a] indicates the best weight to reach a

  pq.emplace(1, 0, 0);
  best[1] = 0;
  while (!pq.empty()) {
	const state s = pq.top();
	pq.pop();

	if (best.contains(s.at) && s.weight_so_far > best[s.at]) {
	  continue;
	}

	// here we commit to exploring
	from[s.at] = s.from;
	if (s.at == v) {
	  break;
	}

	if (!adj.contains(s.at)) {
	  cout << -1 << endl;
	  return EXIT_SUCCESS;
	}
	for (const auto& [dest, weight] : adj.at(s.at)) {
	  const uint64_t new_weight = s.weight_so_far + weight;
	  if (best.contains(dest) && new_weight >= best.at(dest)) {
		continue;
	  }
	  best[dest] = new_weight;
	  pq.emplace(dest, s.at, new_weight);
	}
  }

  uint32_t at = v;
  if (!from.contains(at)) {
	cout << -1 << endl;
	return EXIT_SUCCESS;
  }

  vector<uint32_t> path;
  while (at != 0) {
	path.push_back(at);
	const auto pot_at = from.find(at);
	if (pot_at == from.end()) {
	  cout << "PENIS" << endl;
	  return EXIT_SUCCESS;
	}
	at = pot_at->second;
  }
  ranges::reverse(path);
  for (const auto node : path) {
	cout << node << " ";
  }
}