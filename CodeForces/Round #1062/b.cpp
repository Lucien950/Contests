#include <iostream>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	array<size_t, 26> freq_s{}, freq_t{};
	for (const char c : s) {
	  freq_s[c - 'a'] += 1;
	}
	for (const char c : t) {
	  freq_t[c - 'a'] += 1;
	}
	cout << (std::equal(freq_s.begin(), freq_s.end(), freq_t.begin()) ? "YES" : "NO") << endl;
  }
}