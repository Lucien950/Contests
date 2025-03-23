#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  static long long countBadPairs(vector<int>& nums) {
	std::unordered_map<int, long long> d;
	const long long all_pairs = nums.size() * (nums.size() - 1) / 2;
	for (int i = 0; i < nums.size(); i++)
	  d[nums[i] - i]++;
	long long good_pairs = 0;
	for (const auto& [diff, cnt] : d)
	  good_pairs += cnt * (cnt - 1) / 2;
	return all_pairs - good_pairs;
  }
};

int main() {
  vector v{1, 2, 3, 4, 5};
  cout << Solution::countBadPairs(v) << endl;
}