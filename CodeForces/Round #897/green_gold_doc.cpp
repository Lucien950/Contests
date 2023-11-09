#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int casenum = 0; casenum < cases; casenum++) {
		int n;
		cin >> n;
		int arr[n], out[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int idx[10];
		iota(begin(idx), end(idx), 1);
		sort([](int i,int j) { return (i<j); })


		for (int i = 0; i < n; i++) {
			cout << out[i] << " ";
		}
		cout << endl;
	}
}