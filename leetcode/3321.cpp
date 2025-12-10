#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  static vector<long long> findXSum(const vector<int>& nums, const int k, const int x) {
	map<int, int, std::greater<>> m;
	for (int i = 0; i < k; i++) {
	  m[nums[i]]++;
	}

	vector<long long> out{};
	out.reserve(nums.size() - k + 1);
	for (size_t l = 0; l < nums.size() - k + 1; l++) {
	  const size_t r = l + k - 1;

	  long long a = 0;
	  auto at = m.begin();
	  for (int j = 0; j < x && at != m.end(); j++) {
		a += at->first * at->second;
		++at;
	  }
	  out.push_back(a);

	  m[nums[l]]--;
	  m[nums[r]]++;
	}

	return out;
  }
};

int main() {
  for (const long long i : Solution::findXSum({1, 1, 2, 2, 3, 4, 2, 3}, 6, 2)) {
	cout << i << " ";
  }
  cout << endl;
}