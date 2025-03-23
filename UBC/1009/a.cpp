#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int a, b, c;
	cin >> a >> b >> c;

	int max = INT_MIN;
	for (int i = 0; i <= 5; i++) {
	  for (int j = 0; j <= 5; j++) {
		for (int k = 0; k <= 5; k++) {
		  if (i + j + k != 5)
			continue;
		  max = std::max(max, (a + i) * (b + j) * (c + k));
		}
	  }
	}
	cout << max << endl;
  }
}
