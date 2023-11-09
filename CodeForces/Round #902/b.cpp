#include <iostream>

using namespace std;

bool solve() {
	int sLen, tLen;
	string s, t;
	cin >> sLen >> tLen >> s >> t;
	// check that t is an alternating sequence of 1s and 0s
	bool needPatch = false;
	for (int i = 0; i < sLen - 1; i++) {
		if (s[i] == s[i + 1]) {
			needPatch = true;
			break;
		}
	}
	if (!needPatch) {
		return true;
	}

	for (int i = 0; i < tLen - 1; i++) {
		if (t[i] == t[i + 1]) {
			return false;
		}
	}
	if (t[0] != t[tLen - 1]) {
		return false;
	}
	const char frontBackPatch = t[0];
	for (int i = 0; i < sLen - 1; i++) {
		if (s[i] != s[i + 1]) continue;
		if (s[i] == frontBackPatch) return false;
	}
	return true;
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		cout << (solve() ? "Yes" : "No") << endl;
	}
}