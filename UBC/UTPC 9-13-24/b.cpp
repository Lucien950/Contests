#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  auto r = s.begin();
  // l points to the start or the '2' which marks the start of the substring
  // r points to the '2' which marks the end of the substring or the end of s

  // move r to the kth instance of '2'
  int two_count = 0;
  while (true) {
	if (r == s.end())
	  break;
	if (*r == '2') {
	  two_count++;
	}
	if (two_count == k + 1)
	  break;
	++r;
  }
  if (r == s.end()) {
	cout << s.size();
	return EXIT_SUCCESS;
  }

  auto l = s.begin() - 1; // technically not allowed
  unsigned int best_gap = r - l - 1;
  while (r < s.end()) {
	// move l forward to next '2'
	++l;
	while (*l != '2')
	  ++l;
	// move r forward to next '2' or end
	++r;
	while (r < s.end() && *r != '2')
	  ++r;

	const auto c = static_cast<unsigned int>(r - l - 1);
	best_gap = max(best_gap, c);
  }
  cout << best_gap << endl;
}
