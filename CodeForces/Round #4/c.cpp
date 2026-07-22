#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  uint32_t n;
  cin >> n;
  unordered_map<string, uint32_t> m;
  for (uint32_t i = 0; i < n; i++) {
	string s;
	cin >> s;
	auto& x = m[s];
	if (x == 0) {
	  cout << "OK" << endl;
	} else {
	  cout << s << x << endl;
	}
	x++;
  }
}
