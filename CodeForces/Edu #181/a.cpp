#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	string s;
	cin >> s;

	unordered_map<char, int> freqs;
	for (char c : s) {
	  freqs[c]++;
	}

	vector<char> chars;
	for (const auto& c : freqs | views::keys) {
	  chars.push_back(c);
	}
	ranges::sort(chars);
	ranges::reverse(chars);

	for (const char c : chars) {
	  const int count = freqs[c];
	  for (int i = 0; i < count; i++) {
		cout << c;
	  }
	}
	cout << "\n";
  }
  cout << flush;
}