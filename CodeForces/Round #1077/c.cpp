#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_set>
using namespace std;

static array<int, 200000> base_a;
static array<int, 200000> base_sorted_a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	span a{base_a.begin(), n};
	span sorted_a{base_sorted_a.begin(), n};

	for (size_t i = 0; i < n; i++)
	  cin >> a[i];

	ranges::copy(a, sorted_a.begin());
	ranges::sort(sorted_a);

	unordered_set<int> unsorted_values{};
	for (size_t i = 0; i < n; i++) {
	  if (a[i] != sorted_a[i]) {
		unsorted_values.insert(a[i]);
	  }
	}
	if (unsorted_values.empty()) {
	  cout << "-1\n";
	  continue;
	}

	int out = INT_MAX;
	const int smallest = *ranges::min_element(a), largest = *ranges::max_element(a);
	for (const int v : unsorted_values) {
	  const int best_case = max(v - smallest, largest - v);
	  out = min(out, best_case);
	}
	cout << out << '\n';
  }
  cout << flush;
}