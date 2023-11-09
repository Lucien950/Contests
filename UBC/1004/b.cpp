#include <iostream>
#include<limits>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int t = 0; t < cases; t++) {
		int n;
		cin >> n;
		long long sumA = 0, sumB = 0, minA = std::numeric_limits<int>::max(), minB = std::numeric_limits<int>::max();
		for (int i = 0; i < n; i++) {
			long long ai;
			cin >> ai;
			sumA += ai;
			minA = min(minA, ai);
		}
		for (int i = 0; i < n; i++) {
			long long bi;
			cin >> bi;
			sumB += bi;
			minB = min(minB, bi);
		}
		cout << min(minA * n + sumB, minB * n + sumA) << endl;
	}
}