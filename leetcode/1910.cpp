#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  static string removeOccurrences(string s, string part) {
	vector<bool> keep(s.size(), true);
	size_t keep_count = s.size();

	for (int start = 0; start < s.size();) {
	  while (!keep[start])
		start++;
	  int match_count = 0;
	  for (int at = start; match_count < part.size() && at < s.size() && s[at] == part[match_count];) {
		do
		  at++;
		while (!keep[at]);
		match_count++;
	  }
	  if (match_count == part.size()) {
		for (int at = start, i = 0; i < part.size(); i++) {
		  keep[at] = false;
		  do
			at++;
		  while (!keep[at]);
		}
		cout << "removed from " << start << " to " << start + part.size() << endl;

		for (int back = 0; back < part.size() && start > 0; back++) {
		  while (!keep[start] && start > 1)
			start--; // these don't count
		  start--;
		}
		keep_count -= part.size();
	  } else {
		start++;
	  }
	}

	string out;
	out.reserve(keep_count);
	for (int i = 0; i < s.size(); i++)
	  if (keep[i])
		out += s[i];
	return out;
  }
};

int main() { cout << Solution::removeOccurrences("ccctltctlltlb", "ctl") << endl; }