#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  static int maximumUniqueSubarray(vector<int>& nums) {
	unordered_set<int> window;
	int m = 0, sum = 0;
	for (auto l = nums.begin(), r = nums.begin(); r != nums.end(); ++l) {
	  // increment r until something shows up in the window
	  for (; !window.contains(*r) && r != nums.end(); ++r) {
		window.insert(*r);
		sum += *r;
	  }
	  m = max(m, sum);
	  window.erase(*l);
	  sum -= *l;
	}
	return m;
  }
};