#include <cassert>
#include <chrono>
#include <optional>
#include <vector>

using namespace std;

class Solution {
public:
  static void update_c1_c2(int& c1, int& c2, const int streak, const optional<int> last_size) {
	// nums[i] <= last_element
	// namely the streak has ended
	c2 = max(c2, streak);
	if (last_size.has_value()) {
	  c1 = max(c1, min(streak, last_size.value()));
	}
  }

  static int maxIncreasingSubarrays(const vector<int>& nums) {
	int c1 = 0, c2 = 0; // {s_1, s_2}

	int streak = 1;
	optional<int> last_streak = nullopt;
	for (size_t i = 1; i < nums.size(); i++) {
	  if (nums[i] > nums[i - 1]) {
		// maintain streak
		streak++;
		continue;
	  }
	  update_c1_c2(c1, c2, streak, last_streak);

	  // maintain streak, laststreak
	  last_streak = streak;
	  streak = 1;
	}
	// handle streak end one last time
	update_c1_c2(c1, c2, streak, last_streak);
	return max(c1, c2 / 2);
  }
};

int main() {}