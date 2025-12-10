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
	// if complexity is not increasing, then return 0
	if (complexity[0] >= complexity[1]) {
	  return 0;
	}
	for (size_t i = 2; i < complexity.size(); i++) {
	  if (complexity[i - 1] > complexity[i]) {
		return 0;
	  }
	}
	// we know that complexity is now increasing
	// return (complexity.size() - 1)! mod 1e9 + 7
	return factorialMod(static_cast<int>(complexity.size()) - 1);
  }
};

int main() { cout << Solution::countPermutations({1, 2, 3}) << endl; }