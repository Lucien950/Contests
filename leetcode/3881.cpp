#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  static long long maxSubarraySum(const vector<int>& nums, const int k) {
	long long prefix_sum = 0, max_sum = numeric_limits<long long>::min();
	vector min_so_far_mod_k(k, numeric_limits<long long>::max());
	min_so_far_mod_k[k - 1] = 0; // this is because when you go [0,k-1] (namely i=k-1, k elements) you need a backstop
	for (int i = 0; i < nums.size(); i++) {
	  prefix_sum += nums[i];
	  max_sum = max(max_sum, prefix_sum - min_so_far_mod_k[i % k]);
	  min_so_far_mod_k[i % k] = min(min_so_far_mod_k[i % k], prefix_sum);
	}

	return max_sum;
  }
};

int main() { cout << Solution::maxSubarraySum({1, 2}, 1) << endl; }