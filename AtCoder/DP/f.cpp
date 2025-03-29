#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum direction : char { NONE, LEFT, TOP, DIAG };
// constexpr size_t MAX_STRING_LEN = 3000;
// static array<array<int, MAX_STRING_LEN>, MAX_STRING_LEN> dp_v{};
// static array<array<direction, MAX_STRING_LEN>, MAX_STRING_LEN> dp{};

int main() {
  string s, t;
  cin >> s >> t;
  assert(s.size() <= 3000);
  assert(t.size() <= 3000);

  vector dp_v(s.size(), vector<int>(t.size()));
  vector dp(s.size(), vector<direction>(t.size()));
  static_assert(sizeof(dp_v[0][0]) == 4);
  static_assert(sizeof(dp[0][0]) == 1);

  for (uint16_t i = 0; i < s.size(); i++) {
	for (uint16_t j = 0; j < t.size(); j++) {
	  if (s[i] == t[j]) {
		dp_v[i][j] = (i - 1 >= 0 && j - 1 >= 0 ? dp_v[i - 1][j - 1] : 0) + 1;
		dp[i][j] = DIAG;
	  } else if (const int take_val = max(i - 1 < 0 ? 0 : dp_v[i - 1][j], j - 1 < 0 ? 0 : dp_v[i][j - 1]);
	             i - 1 >= 0 && dp_v[i - 1][j] == take_val) {
		dp_v[i][j] = take_val;
		dp[i][j] = TOP;
	  } else if (j - 1 >= 0 && dp_v[i][j - 1] == take_val) {
		dp_v[i][j] = take_val;
		dp[i][j] = LEFT;
	  } else {
		dp[i][j] = NONE;
	  }
	}
  }

  pair<int16_t, int16_t> at = {t.size() - 1, s.size() - 1};
  stringstream out{};
  while (at.first >= 0 && at.second >= 0) {
	if (dp[at.second][at.first] == DIAG) {
	  out << s[at.second];
	  at.first--;
	  at.second--;
	} else if (dp[at.second][at.first] == LEFT) {
	  at.first--;
	} else if (dp[at.second][at.first] == TOP) {
	  at.second--;
	} else {
	  assert(at.first == 0 && at.second == 0);
	  break;
	}
  }
  string result = out.str();
  ranges::reverse(result);
  cout << result << endl;
}