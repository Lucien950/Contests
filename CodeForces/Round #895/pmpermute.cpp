#include <iostream>
#include <cstring>
#include <cassert>

using std::cin, std::cout, std::endl, std::string;


// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(long long int a, long long int b) {
	return ((a / gcd(a, b)) * b);
}

long long sumToN(long long start, long long end) {
	return (end - start + 1) * (start + end) / 2;
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	long long smallCount = n / y, bigCount = n / x, overlapCount = ((long long) n) / lcm(x, y);
	long long lower = smallCount - overlapCount, upper = n - (bigCount - overlapCount) + 1;
	// cout << lower << " " << upper << endl;
	long long score = sumToN(upper, n) - sumToN(1, lower);
	cout << score << endl;
}

int main() {
	int runs;
	cin >> runs;
	for (int i = 0; i < runs; i++) {
		solve();
	}
}