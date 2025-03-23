#include <iostream>
using namespace std;

class Solution {
  static bool is_punishment(const string& s, const int target, const int at) {
	if (target == 0 && s.size() == at)
	  return true;
	if (target < 0 || at > s.size())
	  return false;
	return is_punishment(s, target - (s[at] - '0'), at + 1) ||
	       is_punishment(s, target - ((s[at] - '0') * 10 + (s[at] - '0')), at + 2) ||
	       is_punishment(s, target - ((s[at] - '0') * 100 + (s[at + 1] - '0') * 10 + (s[at + 2] - '0')), at + 3);
  }

public:
  static int punishmentNumber(const int n) {
	int out = 0;
	for (int i = 1; i <= n; i++) {
	  if (is_punishment(to_string(i * i), i, 0)) {
		cout << i << endl;
		out += i * i;
	  }
	}
	return out;
  }
};

int main() { Solution::punishmentNumber(10); }