#include <cstdint>
#include <iostream>
#include <optional>

using namespace std;

static uint64_t move_char_side_cost(const string& s, const char mover) {
  uint64_t out = 0;
  // note that these are noninclusive
  // namely s[char_left_index] != mover, and s[char_right_index] != mover
  // however s[char_left_index - 1] == mover, and s[char_right_index + 1] == mover (if in bounds)
  int64_t char_left_index = 0, char_right_index = s.size() - 1;

  for (const auto& c : s) {
	if (c != mover) {
	  break;
	}
	char_left_index++;
  }

  for (auto it = s.rbegin(); it != s.rend(); ++it) {
	if (*it != mover) {
	  break;
	}
	char_right_index--;
  }

  for (uint32_t i = char_left_index; i < char_right_index; i++) {
	if (s[i] != mover)
	  continue;
	// s[i] == mover
	if (const uint64_t left_move_cost = i - char_left_index, right_move_cost = char_right_index - i;
	    left_move_cost < right_move_cost) {
	  out += left_move_cost;
	  char_left_index++;
	} else {
	  out += right_move_cost;
	  char_right_index--;
	}
  }

  return out;
}

int main() {
  uint32_t t;
  cin >> t;
  while (t--) {
	uint32_t n;
	cin >> n;
	string s;
	cin >> s;

	// move a strategy
	uint64_t move_a_strat = move_char_side_cost(s, 'a');
	// move b strategy
	uint64_t move_b_strat = move_char_side_cost(s, 'b');
	cout << min(move_a_strat, move_b_strat) << "\n";
  }
  cout << flush;
}