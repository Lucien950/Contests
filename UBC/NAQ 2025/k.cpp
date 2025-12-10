#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int32_t ans;
  uint32_t hit_x, hit_y;

  for (constexpr array<pair<uint32_t, uint32_t>, 3> guesses{{{2, 2}, {4, 2}, {2, 4}}};
       const auto& [guess_x, guess_y] : guesses) {
	cout << "? " << guess_x << " " << guess_y << endl;
	cin >> ans;
	if (ans == 1) {
	  hit_x = guess_x;
	  hit_y = guess_y;
	  goto has_hit;
	}
	if (ans == -1) {
	  return EXIT_SUCCESS;
	}
  }
  hit_x = 4;
  hit_y = 4;

  // you need at least two guesses once you get a hit to identify the top left corner
has_hit:
  const int32_t probe_y = hit_y == 0 ? 1 : -1, probe_x = hit_x == 0 ? 1 : -1;
  cout << "? " << hit_x + probe_x << " " << hit_y << endl;
  int32_t ans_1;
  cin >> ans_1;
  if (ans_1 == -1)
	return EXIT_SUCCESS;
  const bool should_shift_left = (probe_x == -1 && ans_1 == 1) || (probe_x == 1 && ans_1 == 0);

  cout << "? " << hit_x << " " << hit_y + probe_y << endl;
  int32_t ans_2;
  cin >> ans_2;
  if (ans_2 == -1)
	return EXIT_SUCCESS;
  const bool should_shift_up = (probe_y == -1 && ans_2 == 1) || (probe_y == 1 && ans_2 == 0);

  const uint32_t tl_x = hit_x - should_shift_left, tl_y = hit_y - should_shift_up;
  cout << "! " << tl_x << " " << tl_y << endl;
}
