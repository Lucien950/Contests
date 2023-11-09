#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int b[2 * (size_t) 1e5];
vector<int> adjAfterShiftedBy[2 * (size_t) 1e5];
bool stackVisited[2 * (size_t) 1e5];
bool hasChildren[2 * (size_t) 1e5];

template<class T>
inline T mod(T a, T b) {
	T ret = a % b;
	return (ret >= 0) ? (ret) : (ret + b);
}

bool dfs(int atIndex, int moreLength) {
	if (moreLength == 0) return true;
	stackVisited[atIndex] = true;
	for (int nextIndex: adjAfterShiftedBy[atIndex]) {
		if (stackVisited[nextIndex]) return true;
		if (dfs(nextIndex, moreLength - 1)) return true;
	}
	stackVisited[atIndex] = false;
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int bLen, opCount;
		cin >> bLen >> opCount;
		for (int i = 0; i < bLen; i++) {
			cin >> b[i];
			adjAfterShiftedBy[i].clear();
		}

		for (int i = 0; i < bLen; i++) {
			if (b[i] > bLen) continue;
			int distToLevel = (b[i] - 1) - i; // at index - to index
			adjAfterShiftedBy[distToLevel].push_back(mod(distToLevel - b[i], bLen));
			hasChildren[distToLevel] = true;
		}

		bool hasLongEnoughPath = false;
		for (int p = 0; p < bLen; p++) {
			if (!hasChildren[p]) continue;
			memset(stackVisited, false, bLen * sizeof(bool));
			hasLongEnoughPath = dfs(p, opCount);
			if (hasLongEnoughPath) {
				cout << "Yes" << endl;
				break;
			}
		}
		if (!hasLongEnoughPath) cout << "No" << endl;
	}
}