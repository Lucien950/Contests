#include <iostream>
#include <numeric>
#include <optional>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  static int minSubarray(const vector<int>& nums, const int p) {
	const int k = static_cast<int>(accumulate(nums.begin(), nums.end(), 0ULL) % p);
	if (k == 0)
	  return 0;
	vector prefix_mod_p(nums.size() + 1, 0);
	partial_sum(
	    nums.begin(), nums.end(), prefix_mod_p.begin() + 1,
	    [p = static_cast<unsigned long long>(p)](const unsigned long long a, const int b) { return (a + b) % p; });

	optional<size_t> min_gap = nullopt;
	// takes in a residual class of k, returns the latest time we saw it
	// vector<optional<size_t>> latest_prefix_is_x_mod_p(p, nullopt);
	unordered_map<int, size_t> latest_prefix_is_x_mod_p;
	for (size_t at_index = 0; at_index < prefix_mod_p.size(); at_index++) {
	  if (const int want_res_class = (prefix_mod_p[at_index] - k + p) % p;
	      latest_prefix_is_x_mod_p.contains(want_res_class)) {
		const size_t gap = at_index - latest_prefix_is_x_mod_p.at(want_res_class);
		if (min_gap.has_value()) {
		  min_gap = min(min_gap.value(), gap);
		} else {
		  min_gap = gap;
		}
	  }
	  latest_prefix_is_x_mod_p[(prefix_mod_p[at_index] + p) % p] = at_index;
	}

	return min_gap.has_value() && min_gap.value() < nums.size() ? static_cast<int>(min_gap.value()) : -1;
  }
};

int main() { cout << Solution::minSubarray({17, 3, 16, 12, 3, 19, 1, 8, 5, 8}, 54) << endl; }