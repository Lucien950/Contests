#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

static bool solve(const string& s, const size_t half_bottles) {
  int w1 = 0;
  for (int i = 0; i < half_bottles; i++) {
	if (s[i] == 'W')
	  w1++;
  }
  if (w1 % 2 == 1)
	return false;
  // w1 is even
  int w_prefix = 0;
  for (int i = 0; i < half_bottles; i++) {
	if (s[i] == 'W')
	  w_prefix++;
	else
	  break;
  }
  if (w_prefix < w1 / 2)
	return false;
  // w_prefix >= w1/2
  int r2 = 0;
  for (size_t i = half_bottles; i < 2 * half_bottles; i++) {
	if (s[i] == 'R')
	  r2++;
  }
  if (r2 % 2 != 0)
	return false;
  int suffix_r = 0;
  for (size_t i = 2 * half_bottles - 1; i >= half_bottles; i--) {
	if (s[i] == 'R')
	  suffix_r++;
	else
	  break;
  }
  if (suffix_r < r2 / 2)
	return false;
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t half_bottles;
	string s;
	cin >> half_bottles >> s;
	cout << (solve(s, half_bottles) ? "YES" : "NO") << endl;
  }
}