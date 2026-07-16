#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

// note that S_r = {n in T_r, \exists K\subset T_r, |K|=k, LCA(K)=n}
// we claim that LCA(K) = n iff not (all k is a child of one child of n)
// in particular, \exists K\subset T_r, |K|=k, LCA(K)=n iff
// \exists K\subset T_r, |K|=k, not (all k in K is a child of one child of n)

// returns how many children this guy has
uint32_t dfs(const uint32_t at, vector<bool>& explored, const unordered_map<uint32_t, vector<uint32_t>>& adj,
             const uint32_t n, const uint32_t k, uint64_t& out) {
  vector<uint32_t> c{};
  explored[at] = true;
  for (const uint32_t child : adj.at(at)) {
	if (explored[child])
	  continue;
	c.push_back(dfs(child, explored, adj, n, k, out));
  }
  const uint32_t sum_c = accumulate(c.begin(), c.end(), 0u);
  // pushing back to represent the other nodes in the tree
  // (this is another child branch)
  c.push_back(n - 1 - sum_c);

  // suppose the root is down one of these other branches?
  // in particular, we want to find |{i for ci in c if n - 1 - c_i >= k}| which is equal to  |{i for ci in c if n - 1 -
  // k >= c_i}| then add this number to out
  for (const uint32_t ci : c) {
	out += (n - k >= ci) * ci;
  }
  // suppose this node is the root, in particular we are looking for a combination of this node plus a bunch of children
  out += n >= k;
  return sum_c + 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t n, k;
	cin >> n >> k;
	unordered_map<uint32_t, vector<uint32_t>> adj{};
	vector explored(n + 1, false);
	for (uint32_t i = 0; i < n - 1; i++) {
	  uint32_t u, v;
	  cin >> u >> v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	}

	// arbitrarily, let us traverse starting at 1
	uint64_t out = 0;
	(void)dfs(1, explored, adj, n, k, out);
	cout << out << '\n';
  }
  cout << flush;
}
