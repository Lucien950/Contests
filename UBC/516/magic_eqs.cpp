#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int main() {
	int cases, a;
	cin >> cases;
	for (int t = 0; t < cases; t++) {
		cin >> a;
		int aOneCount = 0;
		while (a > 0) {
			if (a % 2 == 1) {
				aOneCount++;
			}
			a /= 2;
		}
		cout << fixed << setprecision(0) << pow(2, aOneCount) << endl;
	}
}