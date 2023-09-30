#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int shortSides = a[0] + a[1], longSide = a[2];
	cout << max(0, longSide - shortSides + 1) << endl;
}