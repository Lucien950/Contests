#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	int n, m;
	cin >> n >> m;

	// given a starting square, gives a list of squares it can jump to
	vector dests_from(n + 1, vector<int>{});
	for (int i = 0; i < m; i++) {
	  int u, v;
	  cin >> u >> v;
	  dests_from[u].push_back(v);
	}

	vector e_moves_to(n + 1, INT_MAX);
	e_moves_to[0] = -1;
	for (int i = 1; i < n + 1; i++) {
	  e_moves_to[i] = min(e_moves_to[i], e_moves_to[i - 1] + 1); // jump from behind (using main bridge)
	  for (const auto& dest : dests_from[i]) {
		e_moves_to[dest] = min(e_moves_to[dest], e_moves_to[i] + 1); // prejump forwards
	  }
	}

	int latest_winnable = -1;
	for (int at = 1; at < n; at++) {
	  // ReSharper disable once CppRedundantComplexityInComparison
	  cout << !(latest_winnable > at); // winning condition for bessie
	  if (!dests_from[at].empty())
		latest_winnable = max(latest_winnable, std::ranges::max(dests_from[at]) - (e_moves_to[at] + 1));
	}
	cout << endl;
  }
  return EXIT_SUCCESS;
}