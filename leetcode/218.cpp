#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
  struct point {
	int x;
	int h;
	bool is_end;
	auto operator<=>(const point& other) const {
	  if (const auto c = x <=> other.x; c != 0)
		return c;
	  // note we want to process the starters first, then process the enders at a given x
	  // we also want to process the shortest starters first, and the tallest enders first
	  return h * (is_end ? 1 : -1) <=> other.h * (other.is_end ? 1 : -1);
	}
  };

public:
  static vector<vector<int>> getSkyline(const vector<vector<int>>& b) {
	vector<point> points;
	for (auto& i : b) {
	  points.push_back({i[0], i[2], false});
	  points.push_back({i[1], i[2], true});
	}

	multiset<int> height; // represents the heights of the buildings which are currently "in play"
	height.insert(0);
	sort(points.begin(), points.end());

	int prev_max_height = 0;
	vector<vector<int>> ans;
	for (const auto& [x, h, is_end] : points) {
	  if (is_end)
		height.erase(height.find(h));
	  else
		height.insert(h);

	  if (int curr_max_height = *height.rbegin(); curr_max_height != prev_max_height) {
		ans.push_back({x, curr_max_height});
		prev_max_height = curr_max_height;
	  }
	}
	return ans;
  }
};