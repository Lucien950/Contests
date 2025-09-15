#include <array>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
	std::array<bool, 26> broken{};
	for (const char b : brokenLetters) {
	  broken[b - 'a'] = true;
	}

	int out = 0;
	auto start = text.begin();
	while (start != text.end()) {
	  bool typable = true;
	  auto end = start;
	  while (end != text.end() and *end != ' ') {
		if (typable && broken[*end - 'a']) {
		  typable = false;
		  out++;
		}
		cout << *end << endl;
		++end;
	  }

	  start = end + (end != text.end());
	}
	return out;
  }
};