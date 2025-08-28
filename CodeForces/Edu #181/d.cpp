#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int64_t MOD = 998244353;

/**
 * @param a
 * @return The inverse modular of a under MOD. Namely, a * inv(a) % MOD == 1.
 */
static uint64_t inv(const uint64_t a) { return a <= 1 ? a : MOD - MOD / a * inv(MOD % a) % MOD; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  struct range {
	uint64_t l, r, prob, prob_c;
  };

  vector<range> ranges(n);
  for (int i = 0; i < n; i++) {
	uint64_t p, q;
	cin >> ranges[i].l >> ranges[i].r >> p >> q;
	ranges[i].prob = p * inv(q) % MOD;
	ranges[i].prob_c = (q - p) * inv(q) % MOD;
  }

  // sort by end position
  ranges::sort(ranges, [](const range& a, const range& b) { return a.r < b.r || (a.r == b.r && a.l < b.l); });
  // maps new range starts to their probabilities
  vector<uint64_t> wthelly(m + 2, 0);
  wthelly[1] = std::accumulate(ranges.begin(), ranges.end(), 1ULL,
                               [](const uint64_t acc, const range& r) { return acc * r.prob_c % MOD; });

  for (const auto& [l, r, prob, prob_c] : ranges) {
	wthelly[r + 1] = (wthelly[l] * inv(prob_c) % MOD * prob % MOD + wthelly[r + 1]) % MOD;
  }
  cout << wthelly[m + 1] << endl;
}