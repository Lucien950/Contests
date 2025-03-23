#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int lampCount;
	string final;
	cin >> lampCount >> final;

	bool has_unpaired = false;
	bool has_unpaired_twos = false;
	for (int i = 0; i < lampCount; i++) {
	  if (final[i] == '1') {
		int start = i;
		while (i < lampCount && final[i] == '1')
		  i++;
		int end = i;
		int streak = end - start;
		if (streak == 2)
		  has_unpaired_twos = !has_unpaired_twos;
		else if (streak % 2 == 1)
		  has_unpaired = !has_unpaired;
	  }
	}

	cout << (!has_unpaired && !has_unpaired_twos ? "YES" : "NO") << endl;
  }
}