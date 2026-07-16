#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct m {
  size_t min;
  size_t max;
};
optional<m> dfs(const size_t at, const vector<vector<size_t>>& children, const vector<size_t>& values) {
  vector<m> child_values{};
  for (const size_t c : children[at]) {
	const optional<m> x = dfs(c, children, values);
	if (not x) {
	  return nullopt;
	}
	child_values.push_back(x.value());
  }

  if (child_values.empty()) {
	assert(values[at] != 0);
	return m{values[at], values[at]};
  }
  assert(values[at] == 0);

  const size_t n = child_values.size();
  const size_t o =
      min_element(child_values.begin(), child_values.end(), [](const m& a, const m& b) { return a.min < b.min; }) -
      child_values.begin();
  for (size_t i = 0; i < n - 1; i++) {
	if (child_values[(i + o) % n].max > child_values[(i + o + 1) % n].min) { // order violation
	  return nullopt;
	}
  }

  return m{child_values[o].min, child_values[(o - 1 + n) % n].max};
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	vector<vector<size_t>> children;
	children.resize(n + 1);
	vector<size_t> values(n + 1);
	for (size_t i = 2; i <= n; i++) {
	  size_t parent;
	  cin >> parent;
	  children[parent].push_back(i);
	}
	for (size_t i = 1; i <= n; i++) {
	  cin >> values[i];
	}
	// root at 1 always :)
	cout << (dfs(1, children, values).has_value() ? "YES" : "NO") << endl;
  }
}