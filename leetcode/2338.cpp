#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  static int idealArraysSlow(const int n, const int maxValue) {
	vector<unsigned int> freq(maxValue + 1, 1), temp(maxValue + 1, 1);

	freq[0] = 0; // just for safety
	temp[0] = 0;

	// turn 1 already implicitly populated
	for (int turn = 1; turn < n; turn++) {
	  // turn denotes how many array slots are required
	  std::swap(freq, temp);
	  fill(freq.begin(), freq.end(), 0);
	  for (int i = 1; i <= maxValue; i++) {
		for (int mult = 1; i * mult <= maxValue; mult++) { // here, we "append" a mult at the end
		  freq[i * mult] = (freq[i * mult] + temp[i]) % MOD;
		}
	  }
	}
	return std::accumulate(freq.begin(), freq.end(), 0, [&](const int a, const int b) { return (a + b) % MOD; });
  }

  static int idealArrays(const int n, const int maxValue) {
	vector sieve(maxValue + 1, 0);
	for (int base = 2; base <= maxValue; base++) {
	  if (sieve[base] != 0)
		continue;
	  for (int multiple = 1; multiple * base <= maxValue; multiple++) {
		sieve[multiple] = base;
	  }
	}
  }
};

int main() {
  std::random_device rd;                       // Seed for the random number engine
  std::mt19937 gen(rd());                      // Mersenne Twister random number generator
  std::uniform_int_distribution<> dis(2, 100); // Range [2, 10000]

  for (int i = 0; i < 10; i++) {
	const int r1 = dis(gen), r2 = dis(gen);
	assert(Solution::idealArraysSlow(r1, r2) == Solution::idealArrays(r1, r2));
	cout << "Test case " << i + 1 << " passed" << endl;
  }
}