#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, m;
	cin >> n >> m;
	const bool can_arrive = n >= m;
	const bool can_slingshot = (n - m) % 2 == 0;
	cout << (can_arrive && can_slingshot ? "YES" : "NO") << endl;
  }
  return 0;
}