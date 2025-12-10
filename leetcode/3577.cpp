#include <iostream>
#include <vector>
using namespace std;

class Solution {
  static int factorialMod(const int n) {
	constexpr int MOD = 1e9 + 7;
	long long result = 1;
	for (int i = 2; i <= n; i++) {
	  result = (result * i) % MOD;
	}
	return static_cast<int>(result);
  }

public:
  static int countPermutations(const vector<int>& complexity) {
	for (const auto c : complexity) {
	  if (c <= complexity[0]) {
		return 0;
	  }
	}
	return factorialMod(static_cast<int>(complexity.size()) - 1);
  }
};

int main() { cout << Solution::countPermutations({1, 2, 3}) << endl; }