#include <iostream>
using namespace std;

static int ceildiv(const int a, const int b) { return (a + b - 1) / b; }

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, m, d;
	cin >> n >> m >> d;
	const int tower_height = d / m + 1;
	cout << ceildiv(n, tower_height) << endl;
  }
}