#include <iostream>
#include <cstring>
#include <set>
#include <array>

using namespace std;

int main() {
	int t;
	cin >> t;
	int a[100];
	std::array<int, 100> b{};
	while (t--) {
		b.fill(3);
		int n;
		cin >> n;

		set<int> seenNumbers;
		set<int> tagged;
		int qqrst = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (qqrst == 3) continue;
			if (seenNumbers.find(a[i]) != seenNumbers.end()) {
				if (tagged.find(a[i]) != tagged.end()) continue;
				// we've seen this number before.
				b[i] = qqrst;
				qqrst++;
				tagged.insert(a[i]);
			} else {
				seenNumbers.insert(a[i]);
			}
		}
		if (qqrst != 3) {
			cout << "-1" << endl;
		} else {
			for (int i = 0; i < n; i++) {
				cout << b[i] << " ";
			}
			cout << endl;
		}
	}
}