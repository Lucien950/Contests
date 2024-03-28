#include <iostream>
#include <optional>
#include <string.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	int numCount[n];
	memset(numCount, 0, sizeof(numCount));
	for (int i = 0; i < n; i++) {
	  int a;
	  cin >> a;
	  numCount[a]++;
	}

	int maxAns = n;
	for (int i = 0; i < n; i++) {
	  if (numCount[i] == 0) {
		maxAns = i;
		break;
	  }
	}

	// detect singles (which are values that only appear once)
	bool hasSeenSingle = false;
	std::optional<int> secondSingleIndex = std::nullopt;
	for (int i = 0; i < n; i++) {
	  if (numCount[i] != 1)
		continue;
	  // numCount[i] => 1
	  if (!hasSeenSingle) {
		hasSeenSingle = true;
		continue;
	  }
	  // hasSeenOne => true
	  secondSingleIndex = i;
	  break;
	}

	int bobCutoffIndex = secondSingleIndex.has_value() ? secondSingleIndex.value() : maxAns;
	cout << min(maxAns, bobCutoffIndex) << endl;
  }
}