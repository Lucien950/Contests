#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	int minVal = INT_MAX, maxVal = INT_MIN;
	while (n--) {
	  int a;
	  cin >> a;
	  minVal = min(minVal, a);
	  maxVal = max(maxVal, a);
	}

	cout << maxVal - minVal << endl;
  }
}