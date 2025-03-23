#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  unsigned long long t;
  cin >> t;
  while (t--) {
	unsigned long long slots, k;
	cin >> slots >> k;

	vector<unsigned long long> a(slots);
	for (unsigned long long i = 0; i < slots; i++) {
	  cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	unsigned long long last_known_index = 0, floor = 0, have = 0;
	while (true) {
	  have += (a[last_known_index] - floor) * (slots - last_known_index);
	  floor = a[last_known_index];
	  if (have >= k)
		break;
	  do {
		last_known_index++;
		if (last_known_index >= slots)
		  return 1;
	  } while (a[last_known_index] == floor);
	}

	cout << k + last_known_index << endl;
  }
}