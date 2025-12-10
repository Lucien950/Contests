#include <array>
#include <iostream>
#include <set>

using namespace std;
constexpr size_t MAX_N = 2e5;
constexpr size_t MAX_Q = 1e9;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int64_t n, k;
	cin >> n >> k;

	array<uint32_t, MAX_N> r_list{};
	multiset<uint32_t> q_list;

	// fill q
	for (int i = 0; i < n; i++) {
	  uint32_t q_i;
	  cin >> q_i;
	  q_list.insert(q_i);
	}
	// fill r_list
	for (int i = 0; i < n; i++) {
	  cin >> r_list[i];
	}
	sort(r_list.begin(), r_list.begin() + n, greater());

	int out = 0;
	for (const uint32_t r : span(r_list).first(n)) {
	  const int64_t max_q =
	      (k - static_cast<int64_t>(r)) / (static_cast<int64_t>(r) + 1); // r >= 1, hence r + 1 > 0 namely no div by 0

	  auto a = q_list.lower_bound(max_q); // do the find
	  if (a == q_list.end()) {
		--a;
	  } else if (*a != max_q) { // number given is too big
		if (a == q_list.begin())
		  continue;
		--a;
	  }
	  out++;
	  q_list.erase(a);
	  if (q_list.empty())
		break;
	}
	cout << out << endl;
  }
}