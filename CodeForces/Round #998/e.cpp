#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

// this is wrong because you can reduce the amount of connections you make with disjoint set
// i thought the graph had to be copied.
int main() {
  int t;
  cin >> t;
  while (t--) {
	std::map<int, std::unordered_set<int>> f, g;

	int v_count, f_edge_count, g_edge_count;
	cin >> v_count >> f_edge_count >> g_edge_count;
	for (int i = 0; i < f_edge_count; i++) {
	  int u, v;
	  cin >> u >> v;
	  f[u].insert(v);
	  f[v].insert(u);
	}
	for (int i = 0; i < g_edge_count; i++) {
	  int u, v;
	  cin >> u >> v;
	  g[u].insert(v);
	  g[v].insert(u);
	}

	uint64_t ops = 0;
	for (int v = 1; v <= v_count; v++) {
	  uint64_t k = f[v].size(); // suppose we need to remove all connected edges
	  for (const auto& i : g[v]) {
		if (f[v].contains(i))
		  k--; // actually g also contains it so don't remove it
		else
		  k++; // g has but f does not
	  }
	  ops += k;
	}
	assert(ops % 2 == 0);
	ops /= 2;
	cout << ops << endl;
  }
}