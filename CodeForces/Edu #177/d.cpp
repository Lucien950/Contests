#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static array<int, 26> freqs;
constexpr int MOD = 998244353;

uint64_t bpow(uint64_t x, uint64_t p) {
  uint64_t res = 1;
  while (p) {
	if (p % 2) {
	  res = (res * x) % MOD;
	}
	p >>= 1;
	x = (x * x) % MOD;
  }
  return res;
}

uint64_t fact(const uint64_t a) {
  uint64_t res = 1;
  for (int i = 2; i <= a; i++) {
	res = res * i % MOD;
  }
  return res;
}

uint64_t ceil_div(const uint64_t a, const uint64_t b) { return (a + b - 1) / b; }

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t total_length = 0; // total_length <= 5e5 <= MAX_INT = 2e9
	for (int i = 0; i < 26; i++) {
	  cin >> freqs[i];
	  total_length += freqs[i];
	}
	// hence we need two sets
	// one set which sums to floor(sum/2), and another which sums to ceil(sum/2)
	// for each set, we find how many permutations we can run with it

	// dp[i] stores how many ways you can add elements of freq to sum to i
	vector dp(ceil_div(total_length, 2) + 1, 0);
	dp[0] = 1;
	for (const int freq : freqs) {
	  if (freq == 0)
		continue;
	  for (int64_t j = ceil_div(total_length, 2); j - freq >= 0; j--) {
		// namely dp[j] += dp[j-freq] mod MOD
		// note that addition under MOD is preserved
		assert(0 <= j && j < dp.size());
		assert(0 <= j - freq && j - freq < dp.size());
		dp[j] = (dp[j] + dp[j - freq]) % MOD;
	  }
	}

	uint64_t out = fact(ceil_div(total_length, 2)) * fact(total_length / 2) % MOD * dp[total_length / 2] % MOD;
	for (const int freq : freqs) {
	  out = out * bpow(fact(freq), MOD - 2) % MOD;
	}
	cout << out << endl;
  }
}