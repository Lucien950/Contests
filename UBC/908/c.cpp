#include <iostream>
#include <vector>
#include <array>
#include <cstring>

using namespace std;

int b[2 * (size_t) 1e5];
vector<int> adjList[2 * (size_t) 1e5];
bool stackVisited[2 * (size_t) 1e5];
bool hasChildren[2 * (size_t) 1e5];

array<int, 10> a;

template<class T>
inline T mod(T a, T b) {
	T ret = a % b;
	return (ret >= 0) ? (ret) : (ret + b);
}

bool dfs(int atIndex, int moreLength) {
	if (moreLength == 0) return true;
	stackVisited[atIndex] = true;
	for (int nextIndex: adjList[atIndex]) {
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
			adjList[i].clear();
			hasChildren[i] = false;
		}
		// for every element of b, if it was the level node, after the rotation what would be level
		for (int i = 0; i < bLen; i++) {
			if (b[i] > bLen) continue;
			int distToLevel = (b[i] - 1) - i; // at index - to index
			for (int j = 0; j < bLen; j++) {
				// if shifting makes it level
				if (b[j] == mod((j + distToLevel - b[i]), bLen) + 1) {
					adjList[i].push_back(j);
					hasChildren[i] = true;
				}
			}
		}

		//start checking for cycles at current fixed points.
		//make sure operations > cycle length
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
		if (!hasLongEnoughPath) {
			cout << "No" << endl;
		}
	}
}