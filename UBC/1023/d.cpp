#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int problems;
	cin >> problems;

	vector<int> a(problems), b(problems);
	for (int i = 0; i < problems; i++) {
	  cin >> a[i] >> b[i];
	}
  }
}