#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  static int countPartitions(vector<int>& nums) {
	return accumulate(nums.begin(), nums.end(), 0) % 2 == 1 ? 0 : static_cast<int>(nums.size()) - 1;
  }
};