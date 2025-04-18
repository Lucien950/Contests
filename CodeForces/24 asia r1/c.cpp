#include <iostream>

using namespace std;

int sign(const int x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	pair<int, int> a;
	cin >> a.first >> a.second;
	if (sign(a.first) == sign(a.second)) {
	  cout << abs(a.first) + abs(a.second) << endl;
	} else {
	  cout << min(abs(a.first), abs(a.second)) + abs(abs(a.first) - abs(a.second)) << endl;
	}
  }
}