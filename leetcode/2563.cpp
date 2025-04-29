#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  static long long countFairPairs(const vector<int>& nums, const int lower, const int upper) {
	map<int, int> freq;
	for (const int num : nums) {
	  freq[num]++;
	}

	vector<int> unique_nums, freq_prefix;
	unique_nums.reserve(freq.size());
	freq_prefix.reserve(freq.size() + 1);
	freq_prefix.push_back(0);
	for (const auto& [num, count] : freq) {
	  unique_nums.push_back(num);
	  freq_prefix.push_back(freq_prefix.back() + count);
	}

	long long out = 0;
	// implicitly it is sorted
	for (auto l = unique_nums.begin(); l < unique_nums.end(); ++l) {
	  // guess we need to bsearch for r :(
	  auto r_low = ranges::lower_bound(l, unique_nums.end(), lower - *l),
	       r_high = ranges::upper_bound(l, unique_nums.end(), upper - *l) - 1;
	  // range query between r_low and r_high
	  if (r_low == unique_nums.end() || r_low > r_high)
		continue;
	  if (r_low == l) {
		out += freq[*l] * (freq[*l] - 1) / 2;
		++r_low;
	  }
	  out += freq[*l] * (freq_prefix[r_high - unique_nums.begin() + 1] - freq_prefix[r_low - unique_nums.begin()]);
	}
	return out;
  }
};

int main() { cout << Solution::countFairPairs({0, 1, 7, 4, 4, 5}, 3, 6) << endl; }