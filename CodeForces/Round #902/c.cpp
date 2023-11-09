#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> solve() {
	int tLen;
	string t;
	cin >> tLen >> t;
	if (tLen <= 1) return {};
	const int leftMiddleIndex = tLen / 2 - 1;
	//handle middle edge case
	if (t[leftMiddleIndex] == t[tLen - leftMiddleIndex + 1]) return {-1};

	vector<int> tally{};
	int leftOffset = 0, rightOffset = 0;
	for (int i = 0; i <= leftMiddleIndex - 1; i++) {
		if (t[i] != t[tLen - i + 1]) continue;
		const char c = t[i];
		if (c == '1') {
			tally.push_back(i + leftOffset);
			leftOffset += 2;
		} else if (c == '0') {
			tally.push_back(tLen + leftOffset - i - rightOffset);
			rightOffset += 2;
		}
	}
	return tally;
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		std::ostringstream ss;
		vector<int> solution = solve();
		for (size_t i = 0; i < solution.size(); ++i) {
			if (i != 0) ss << " ";
			ss << solution[i];
		}
		cout << ss.str() << endl;
	}
}