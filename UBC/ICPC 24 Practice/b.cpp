#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int64_t n, d;
  cin >> n >> d;

  std::set<int64_t> s;
  for (int i = 0; i < n; i++) {
	int p;
	cin >> p;
	s.insert(p);
  }

  vector v(s.begin(), s.end());
  sort(v.begin(), v.end());

  uint64_t out = 0;
  int64_t last = -1e10;
  for (const int64_t& p : v) {
	if (p - last > d) {
	  last = p;
	  out++;
	}
  }
  cout << out << endl;
  return EXIT_SUCCESS;
}