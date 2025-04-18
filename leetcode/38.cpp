#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
  static string countAndSay(const int n) {
	string out = "1";
	for (int i = 1; i < n; i++) {
	  stringstream temp;
	  for (auto at = out.begin(); at != out.end();) {
		const char at_char = *at;
		int count;
		for (count = 0; *at == at_char && at != out.end(); ++count, ++at)
		  ;
		temp << count << at_char;
	  }
	  out = temp.str();
	}
	return out;
  }
};

int main() { cout << Solution::countAndSay(4) << endl; }