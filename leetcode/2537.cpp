#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  static long long countGood(const vector<int>& nums, const int k) {
	long long out = 0;

	int pairs = 0;
	unordered_map<int, int> window;

	// left pointer inclusive, right noninclusive
	for (auto l = nums.begin(), r = nums.begin(); r != nums.end();) {
	  while (pairs < k && r != nums.end()) {
		// recalculate pairs
		pairs += window[*r];
		window[*r]++;
		++r;
	  }
	  while (pairs >= k) {         // && l != r but then pairs would be sufficiently low
		out += nums.end() - r + 1; // add all subarrays which end to the right of the right pointer
		                           // those are valid because the number of pairs must be greater
		// remove l from the window and remove its pairs
		window[*l]--;
		pairs -= window[*l];
		++l;
	  }
	}

	return out;
  }
};

int main() { cout << Solution::countGood({1, 1, 1, 1, 1}, 10) << endl; }