#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  static int factorial(const int n) {
	int f = 1;
	for (int i = 1; i <= n; ++i)
	  f *= i;
	return f;
  }

  static int count(unordered_map<char, int>& freq, const int capacity, const char last_used_char,
                   unordered_map<char, int>& take_map, const int length) {
	if (capacity < 0)
	  return 0;
	if (capacity == 0) {
	  int out = factorial(length);
	  for (const auto& [c, cnt] : take_map) {
		out /= factorial(cnt);
	  }
	  return out;
	}

	int out = 0;
	for (const auto [c, cnt] : freq) {
	  if (c <= last_used_char)
		continue;
	  for (int i = 1; i <= cnt; i++) {
		freq[c]--;
		take_map[c]++;
		out += count(freq, capacity - i, c, take_map, length);
	  }
	  // remove last p.second characters from take_map
	  freq[c] += cnt;
	  take_map[c] -= cnt;
	}
	return out;
  }

public:
  static int numTilePossibilities(string tiles) {
	// constant time payment
	unordered_map<char, int> m;
	for (const char c : tiles)
	  m[c]++;
	int out = 0;
	unordered_map<char, int> s;
	s.reserve(tiles.size());
	for (int l = 1; l <= tiles.size(); l++) {
	  out += count(m, l, 'A' - 1, s, l);
	}
	return out;
  }
};

int main() { cout << Solution::numTilePossibilities("AAABBC") << endl; }