#include <queue>
#include <unordered_map>
#include <vector>

std::vector<bool> f(const int d, const int p, const int n,
                    const std::unordered_map<int, std::vector<std::pair<int, int>>>& neighbour_weights) {
  std::vector feasible(n, false);
  const int heaviest_travel_weight = d * p;

  std::queue<int> to_explore;
  to_explore.push(0);
  feasible[0] = true;
  while (!to_explore.empty()) {
	const int at = to_explore.front();
	to_explore.pop();
	for (const auto [n_node, n_weight] : neighbour_weights.at(at)) {
	  if (feasible[n_node])
		continue;
	  if (heaviest_travel_weight <= n_weight) {
		to_explore.push(n_node);
		feasible[n_node] = true;
	  }
	}
  }
  return feasible;
}