#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  struct Penis {
	string s;
	int i;
	auto operator<=>(const Penis& other) const { return s <=> other.s; }
  };
  vector<Penis> a;
  a.reserve(n);
  for (int i = 0; i < n; i++) {
	string s;
	cin >> s;
	for (size_t j = 1; j < s.size(); j += 2) {
	  s[j] = static_cast<char>('Z' - s[j] + 'A');
	}
	a.push_back({s, i});
  }
  sort(a.begin(), a.end());
  for (const auto& [s, i] : a) {
	cout << i + 1 << " ";
  }
  cout << endl;
}