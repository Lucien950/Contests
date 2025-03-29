#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  static int countDays(int days, vector<vector<int>>& meetings) {
	// sort by start time
	ranges::sort(meetings, [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
	int out = 0, last_exit = 0;
	for (const auto& meeting : meetings) {
	  out += max(0, meeting[0] - last_exit - 1);
	  last_exit = max(last_exit, meeting[1]);
	}
	return out + max(0, days - last_exit);
  }
};

int main() {
  vector<vector<int>> a = {{5, 7}, {1, 3}, {9, 10}};
  cout << Solution::countDays(10, a) << endl;
}