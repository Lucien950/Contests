#include <array>
#include <iostream>
#include <optional>

using namespace std;

/**
 * @param a The first LED. The first LED can have always on and always off segments, represented by '+' and '-'
 * respectively
 * @param b The second LED.
 * @return True if the two LEDs are ambiguous, false otherwise
 */
static bool is_match(const char a[8], const char b[8]) {
  for (size_t k = 0; k < 7; k++) {
	if (a[k] == '-' || a[k] == '+') {
	  continue;
	}
	if (a[k] != b[k]) {
	  return false;
	}
  }
  return true;
}

/**
 * @param led The representation of the LED
 * @return The value of the number on the LED
 * @note If the LED is ambiguous, or invalid return nullopt
 */
static optional<int> match_string(const char led[8]) {
  optional<int> out = std::nullopt;
  static array<const char[8], 10> reversed_m = {
      "GGGgGGG", "gggggGG", "gGGGGGg", "ggGGGGG", "GggGgGG", "GgGGGgG", "GGGGGgG", "ggGggGG", "GGGGGGG", "GgGGGGG",
  };
  for (int j = 0; j <= 9; j++) {
	if (is_match(led, reversed_m[j])) {
	  if (out.has_value()) {
		return std::nullopt;
	  }
	  out = j;
	}
  }
  return out;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
	char s[8];
	cin >> s;
	if (const auto a = match_string(s); !a.has_value()) {
	  cout << "*";
	} else {
	  cout << a.value();
	}
  }
  cout << endl;
}