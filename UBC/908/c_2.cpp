#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int b[2 * (size_t) 1e5];
vector<int> adjAfterShiftedBy[2 * (size_t) 1e5];
bool stackVisited[2 * (size_t) 1e5];

// this is maximally O(n) due to properties of the graph
bool bfs(int targetDepth) {
	struct explore {
		int at;
		int left;
	};
	queue<explore> toExplore;
	set<int> explored;
	toExplore.push({0, targetDepth});
	while (!toExplore.empty()) {
		explore a = toExplore.front();
		toExplore.pop();
		int at = a.at, left = a.left;
		if (explored.find(at) != explored.end()) return true; // cycle found, we can go round and round
		explored.insert(at);
		if (left == 0) return true;
		for (int adj: adjAfterShiftedBy[at]) {
			toExplore.push({adj, left - 1});
		}
	}
	return false;
}

template<class T>
inline T mod(T a, T b) {
	T ret = a % b;
	return (ret >= 0) ? (ret) : (ret + b);
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
			int shiftsToLevel = mod(i - (b[i] - 1), bLen), // shifts to the left required to make b[i] level
			shiftsToNewLoc = mod(shiftsToLevel + b[i], bLen); // shifts to the right after applying the operation (2)
			adjAfterShiftedBy[shiftsToNewLoc].push_back(shiftsToLevel); // construct an inverted adj list
		}

		bool hasLongEnoughPath = bfs(opCount);
		cout << (hasLongEnoughPath ? "Yes" : "No") << endl;
	}
}
