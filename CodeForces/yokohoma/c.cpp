#include <array>
#include <cstdint>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

constexpr size_t MAX_N = 1e5 + 1;
static array<int64_t, MAX_N> p;
static array<int64_t, MAX_N> dist;
static array<bool, MAX_N> visited;

int main() {
  visited.fill(false);
  dist.fill(INT64_MAX);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
	cin >> p[i];
  }

  unordered_map<int, vector<pair<int, int64_t>>> adj;
  for (int i = 0; i < m; i++) {
	int a, b, q;
	cin >> a >> b >> q;
	adj[a].emplace_back(b, q);
	adj[b].emplace_back(a, q);
  }

  priority_queue<pair<int64_t, int>> toExplore;
  toExplore.emplace(0, 1);
  dist[1] = 0;
  while (!toExplore.empty()) {
	const auto [neg_length, at] = toExplore.top();
	toExplore.pop();
	if (visited[at])
	  continue;
	visited[at] = true;
	for (const auto& [neighbour, weight] : adj[at]) {
	  if (-neg_length + weight >= dist[neighbour])
		continue;
	  dist[neighbour] = -neg_length + weight;
	  toExplore.emplace(-(-neg_length + weight), neighbour);
	}
  }

  uint64_t ans = 0;
  for (int i = 1; i <= n; i++) {
	ans += p[i] * dist[i];
  }
  cout << ans << endl;
}