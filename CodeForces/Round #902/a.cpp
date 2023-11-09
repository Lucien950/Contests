#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool solve() {
	int n;
	cin >> n;
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		freq[x]++;
	}
	if (freq.size() == 1) {
		return true;
	} else if (freq.size() > 2) {
		return false;
	} else {
		// freq.size() == 2
		vector<int> keys;
		keys.reserve(freq.size());
		for (auto i: freq) keys.push_back(i.first);
		return abs(freq.at(keys[0]) - freq.at(keys[1])) <= 1;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (solve() ? "Yes" : "No") << endl;
	}
}