#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
  static int earliestFullBloom(const vector<int>& plantTime, const vector<int>& growTime) {
	int final_day = 0;
	struct plant {
	  int plant_time;
	  int grow_time;
	};
	const auto plant_view = views::iota(0, static_cast<int>(plantTime.size())) |
	                        views::transform([&](const int i) { return plant{plantTime[i], growTime[i]}; });
	vector plants(plant_view.begin(), plant_view.end());
	// sort by decreasing growTime
	ranges::sort(plants, [&](const plant a, const plant b) { return a.grow_time > b.grow_time; });

	int cur_day = 0;
	for (const auto [pt_i, gt_i] : plants) {
	  final_day = max(final_day, cur_day + pt_i + gt_i);
	  cur_day += pt_i;
	}
	return final_day;
  }
};

int main() { cout << Solution::earliestFullBloom({1, 4, 3}, {2, 3, 1}) << endl; }