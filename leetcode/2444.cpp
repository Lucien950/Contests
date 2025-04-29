#include <bits/atomic_lockfree_defines.h>
#include <iostream>
#include <optional>
#include <span>
#include <vector>

using namespace std;

class Solution {
  using nums_it = vector<int>::const_iterator;

  /**
   * @param start start of range
   * @param end end of range
   * @param a instances of a
   * @param b instances of b
   * @returns number of subarrays between start and end that have at least one minK and one maxK
   */
  static long long calculateSubarrays(const nums_it start, const nums_it end, const vector<nums_it>& a,
                                      const vector<nums_it>& b) {
	if (a.empty() || b.empty())
	  return 0;
	size_t out = 0;
	auto last_start = start - 1;
	for (auto at_a = a.begin(), at_b = b.begin() + (a[0] == b[0]); at_a != a.end() && at_b != b.end();) {
	  // contribute to out
	  // in particular the range from last_start to min(at_b) times the range from max(at_a, at_b) to end
	  const size_t s_range = distance(last_start, min(*at_a, *at_b)), e_range = distance(max(*at_a, *at_b), end);
	  out += s_range * e_range;
	  last_start = min(*at_a, *at_b);
	  // move at_a, at_b to the correct spots
	  if (*at_a < *at_b) { // leap frog at_a over at_b
		++at_a;
	  } else if (*at_b < *at_a) { // leap frog at_b over at_a
		++at_b;
	  } else {
		throw logic_error("*a and *b are equal");
	  }
	}
	return static_cast<long long>(out);
  }

  static long long piss(const nums_it start, const nums_it end) {
	const size_t streak = distance(start, end);
	return static_cast<long long>(streak) * (streak + 1) / 2;
  }

public:
  static long long countSubarrays(const vector<int>& nums, const int minK, const int maxK) {
	long long out = 0;

	auto start = nums.begin();
	vector<nums_it> mins, maxes;
	for (auto at = nums.begin(); at != nums.end(); ++at) {
	  // streak maintainance
	  if (minK <= *at && *at <= maxK) {
		if (*at == minK)
		  mins.push_back(at);
		if (*at == maxK)
		  maxes.push_back(at);
		continue;
	  }
	  // we have made it out of bounds
	  // calculate subarrays
	  out += minK != maxK ? calculateSubarrays(start, at, mins, maxes) : piss(start, at);

	  // end streak
	  start = next(at);
	  mins.clear();
	  maxes.clear();
	}

	// calculate subarrays if streak
	out += minK != maxK ? calculateSubarrays(start, nums.end(), mins, maxes) : piss(start, nums.end());
	return out;
  }
};

int main() {
  cout << Solution::countSubarrays({1, 3, 5, 2, 7, 5}, 1, 5) << endl;
  cout << Solution::countSubarrays({1, 1, 1, 1}, 1, 1) << endl;
  cout << Solution::countSubarrays({1, 2}, 2, 1) << endl;
  cout << Solution::countSubarrays({0, 3, 8, 8, 7, 8, 0, 8, 2, 8, 0, 1, 6, 4, 5}, 0, 8) << endl;
}
