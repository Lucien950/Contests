#include <iostream>

using namespace std;

typedef long long ll;

ll solve() {
	int n;
	ll firstStrength, firstEndurance;
	cin >> n >> firstStrength >> firstEndurance;
	bool bad = false;
	for (int i = 1; i < n; i++) {
		ll atStrength, atEndurance;
		cin >> atStrength >> atEndurance;
		if (!bad && atStrength >= firstStrength && atEndurance >= firstEndurance) {
			bad = true;
		}
	}
	return bad ? -1 : firstStrength;
}


int main() {
	int cases;
	cin >> cases;
	for (int t = 0; t < cases; t++) {
		cout << solve() << endl;
	}
}