#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <span>
using namespace std;

static array<int, 1000000> a_buf{}, b_buf{};

bool solve(const span<int> a, const span<int> b) {
  static array<int, 2000001> sieve{};

  const int max_b = *ranges::max_element(b);
  fill_n(sieve.begin(), max_b + 1, 0); // largest query into sieve is max_b

  const set a_set(a.begin(), a.end());
  const int unique_as = static_cast<int>(a_set.size());

  for (const int aa : a_set) {
	for (int j = aa; j <= max_b; j += aa) {
	  sieve[j] += 1;
	}
  }
  // Single pass over b instead of three separate accumulates
  size_t x_1 = 0, x_3 = 0;
  for (const int bb : b) {
	const int s = sieve[bb];
	x_1 += s == 0;
	x_3 += s == unique_as;
  }

  if (x_3 != x_1) {
	return x_3 > x_1;
  }
  // otherwise, check edge
  const size_t x_2 = b.size() - x_1 - x_3;
  return x_2 % 2 == 1; // alice wins if x_2 is odd
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
	size_t n, m;
	cin >> n >> m;

	for (size_t i = 0; i < n; i++) {
	  cin >> a_buf[i];
	}
	for (size_t i = 0; i < m; i++) {
	  cin >> b_buf[i];
	}
	cout << (solve({a_buf.data(), n}, {b_buf.data(), m}) ? "Alice" : "Bob") << '\n';
  }
}