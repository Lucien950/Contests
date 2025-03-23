#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	long long out = 0, biggestOdd = -1, biggestEven = -1;
	priority_queue<long long, std::vector<long long>, std::greater<>> evens;
	for (int i = 0; i < n; i++) {
	  long long a;
	  cin >> a;
	  if (a % 2 == 0) {
		evens.push(a);
		biggestEven = max(a, biggestEven);
	  } else {
		biggestOdd = max(a, biggestOdd);
	  }
	}

	if (biggestOdd == -1) { // no odds
	  cout << 0 << endl;
	  continue;
	}

	bool has_happened = false;
	while (!evens.empty()) {
	  if (biggestOdd < evens.top()) {
		biggestOdd = biggestOdd + biggestEven;
		assert(!has_happened);
		has_happened = true;
		out++;
	  }
	  biggestOdd = biggestOdd + evens.top();
	  evens.pop();
	  out++;
	}

	cout << out << endl;
  }
}