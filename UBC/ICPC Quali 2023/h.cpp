#include <iostream>
#include <cmath>
#include <deque>
#include <vector>

typedef unsigned long long ULLong;

using namespace std;

// void solveNaive(int required, int maxPerPill, int maxPills) {
// 	deque<int> possibleDoses;
// 	int perPillLowerBound = ceil((double) required / maxPills);
// 	int pillCountLowerBound = ceil((double) required / maxPerPill);
// 	if (maxPerPill - perPillLowerBound < maxPills - pillCountLowerBound) {
// 		for (int pillDose = perPillLowerBound; pillDose <= maxPerPill; pillDose++) {
// 			if (required % pillDose == 0) {
// 				possibleDoses.push_back(pillDose);
// 			}
// 		}
// 	} else {
// 		for (int pillCount = pillCountLowerBound; pillCount <= maxPills; pillCount++) {
// 			if (required % pillCount == 0) {
// 				possibleDoses.push_front(required / pillCount);
// 			}
// 		}
// 	}
// 	cout << possibleDoses.size() << endl;
// 	for (auto dose: possibleDoses) {
// 		cout << dose << endl;
// 	}
// }

ULLong ceilDiv(ULLong a, ULLong b) {
	return 1 + ((a - 1) / b);
}

void solve(ULLong required, ULLong maxPerPill, ULLong maxPills) {
	vector<ULLong> smalls;
	deque<ULLong> bigs;
	ULLong perPillLowerBound = 1 + ((required - 1) / maxPills); //ceil(required / maxPills) w/overflow protection
	ULLong maxN = floor(sqrt(required));
	for (ULLong i = max(1ULL, min(ceilDiv(required, maxPerPill), ceilDiv(required, maxPills))); i <= maxN; i++) {
		if (required % i != 0) continue;
		//consider k = i
		if ((perPillLowerBound <= i) && (i <= maxPerPill)) { //second condition should be held implcitly??
			smalls.push_back(i);
		}
		//consider k = n/i = i'
		ULLong iprime = required / i;
		if ((perPillLowerBound <= iprime) && (iprime <= maxPerPill)) {
			bigs.push_front(required / i);
		}
	}
	cout << smalls.size() + bigs.size() << endl;
	for (ULLong i: smalls) {
		cout << i << endl;
	}
	for (ULLong i: bigs) {
		cout << i << endl;
	}
}

int main() {
	ULLong required, maxPerPill, maxPills;
	cin >> required >> maxPerPill >> maxPills;
	solve(required, maxPerPill, maxPills);
}