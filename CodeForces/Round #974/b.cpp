#include <iostream>
using namespace std;

inline int sum_1_to_n(const int n) { return n * (n + 1) / 2; }

int main() {
  int t;
  cin >> t;
  while (t--) {
	int end_year, lifetime;
	cin >> end_year >> lifetime;
	cout << ((sum_1_to_n(end_year) - sum_1_to_n(end_year - lifetime)) % 2 == 0 ? "YES" : "NO") << endl;
  }
}