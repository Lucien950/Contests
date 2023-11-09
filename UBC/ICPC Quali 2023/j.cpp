#include <iostream>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int l;

	bool drankMinimum = false, drankMaximum = false;
	for (int i = 0; i < n - 1; i++) {
		cin >> l;
		if (l == a) {
			drankMinimum = true;
		} else if (l == b) {
			drankMaximum = true;
		}
	}

	if ((!drankMinimum) && (!drankMaximum)) {
		cout << -1 << endl; //can't make two logs in one day
	} else if (!drankMinimum) {
		cout << a << endl; //must drink the minimum
	} else if (!drankMaximum) {
		cout << b << endl; //must drink the maximum
	} else {
		for (int i = a; i <= b; i++) {
			cout << i << endl;
		}
	}
}