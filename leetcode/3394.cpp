#include <algorithm>
#include <bits/ranges_algo.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // remember, the order is start_x, start_y, end_x, end_y
  static bool checkValidCuts(const int n, vector<vector<int>>& rectangles) {
	// sort be decreasing order of first element
	ranges::sort(rectangles, [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

	// first sweep through the x axis
	int gap_count = 0, last_end_x = 0;
	for (const auto& rectangle : rectangles) {
	  if (rectangle[0] >= last_end_x) {
		gap_count++;
		if (gap_count >= 3)
		  return true;
	  }
	  last_end_x = max(last_end_x, rectangle[2]);
	}

	ranges::sort(rectangles, [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
	// then sweep through y axis
	gap_count = 0;
	int last_end_y = 0;
	for (const auto& rectangle : rectangles) {
	  if (rectangle[1] >= last_end_y) {
		gap_count++;
		if (gap_count >= 3)
		  return true;
	  }
	  last_end_y = max(last_end_y, rectangle[3]);
	}
	// not possible :)
	return false;
  }
};

int main() {
  vector<vector<int>> rectangles{{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
  cout << (Solution::checkValidCuts(5, rectangles) ? "YES" : "NO") << endl;
}