#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static long long countSubarrays(const vector<int>& nums, const int k) {
	const int target = ranges::max(nums);
	long long out = 0;
	vector<vector<int>::const_iterator> targets;
	for (auto at = nums.begin(); at != nums.end(); ++at) {
	  if (*at == target)
		targets.push_back(at);
	}

	// ReSharper disable once CppDFALoopConditionNotUpdated
	for (auto l = targets.begin(); distance(l, targets.end()) > k - 1; ++l) {
	  // pointer into nums
	  const auto last_start = l == targets.begin() ? nums.begin() - 1 : *prev(l);
	  // pointer into target
	  const auto r = next(l, k - 1);
	  assert(r != targets.end()); // just to double check the nonstrict inequality

	  const size_t d1 = distance(last_start, *l), d2 = distance(*r, nums.end());
	  out += d1 * d2;
	}
	return out;
  }
};

int main() {
  cout << Solution::countSubarrays({1, 3, 2, 3, 3}, 2) << endl;
  cout << Solution::countSubarrays(
      {12, 6, 7, 6, 10, 8, 16, 10, 16, 16, 16, 14, 1, 13, 1, 0, 5, 3, 11, 9, 16, 2, 16, 15, 4, 16}, 2);
}