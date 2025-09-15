#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  struct State {
	int cost;
	pair<int, int> at;
	auto operator<=>(const State& other) const { return cost <=> other.cost; }
  };

public:
  static int minTimeToReach(const vector<vector<int>>& moveTime) {
	static constexpr array<pair<int, int>, 4> d = {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}};

	priority_queue<State, vector<State>, greater<>> to_explore;
	to_explore.push({0, {0, 0}});

	const int height = static_cast<int>(moveTime.size()), width = static_cast<int>(moveTime[0].size());
	vector explored(height, vector(width, false));
	explored[0][0] = true;

	while (!to_explore.empty()) {
	  auto [cost, at] = to_explore.top();
	  to_explore.pop();
	  if (at.first == width - 1 && at.second == height - 1) {
		return cost;
	  }
	  for (auto [dx, dy] : d) {
		const pair next = {at.first + dx, at.second + dy};
		// check next in bounds
		if (!(0 <= next.first && next.first < width && 0 <= next.second && next.second < height))
		  continue;
		if (explored[next.second][next.first])
		  continue;
		const int first_move_time = moveTime[next.second][next.first];
		explored[next.second][next.first] = true;
		to_explore.push({max(first_move_time, cost) + 1, next});
	  }
	}
	std::unreachable();
  }
};

int main() {
  // cout << Solution::minTimeToReach({{0, 4}, {4, 4}}) << endl;
  // cout << Solution::minTimeToReach({{0, 0, 0}, {0, 0, 0}}) << endl;
  // cout << Solution::minTimeToReach({{0, 1}, {1, 2}}) << endl;
  cout << Solution::minTimeToReach({{94, 79, 62, 27, 69, 84}, {6, 32, 11, 82, 42, 30}});
}