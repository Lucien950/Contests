#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static array<int, 26> freqs;
constexpr int MOD = 998244353;

/**
 * @param x base
 * @param p power
 * @return x ** p mod MOD
 */
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

/**
 * @param a number to calculate factorial of
 * @return a! mod MOD
 */
uint64_t fact(const uint64_t a) {
  uint64_t res = 1;
  for (int i = 2; i <= a; i++) {
	res = res * i % MOD;
  }
  return res;
}

int64_t ceil_div(const int64_t a, const int64_t b) { return (a + b - 1) / b; }

int main() {
  int t;
  cin >> t;
  while (t--) {
	int64_t total_length = 0; // total_length <= 5e5 <= MAX_INT = 2e9
	for (int i = 0; i < 26; i++) {
	  cin >> freqs[i];
	  total_length += freqs[i];
	}
	// hence we need two sets
	// one set which sums to floor(sum/2), and another which sums to ceil(sum/2)
	// for each set, we find how many permutations we can run with it

	const int64_t odds = ceil_div(total_length, 2);

	// dp[i] stores how many ways you can add elements of freq to sum to i
	vector dp(odds + 1, 0);
	dp[0] = 1;
	for (const int freq : freqs) {
	  if (freq == 0)
		continue;
	  for (int64_t j = odds; j - freq >= 0; j--) {
		// namely dp[j] += dp[j-freq] mod MOD
		// note that addition under MOD is preserved
		dp[j] = (dp[j] + dp[j - freq]) % MOD;
	  }
	}

	// we are trying to find odds! * evens! * dp[evens] / prod(freq[i]) mod MOD
	uint64_t out = fact(odds) * fact(total_length / 2) % MOD * dp[total_length / 2] % MOD;
	for (const int freq : freqs) {
	  out = out * bpow(fact(freq), MOD - 2) % MOD; // rearrangement of fermat's little theorem
	}
	cout << out << endl;
  }
}