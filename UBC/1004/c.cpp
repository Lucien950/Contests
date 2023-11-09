#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

#define OPPCHAR(c) c == '0' ? '1' : '0'

const int MOD = 998244353;


int factorial(const unsigned long long n) {
	long long f = 1;
	for (int i = 1; i <= n; ++i)
		f = (f * i) % MOD;
	return (int) f;
}

int main() {
	int cases;
	cin >> cases;
	for (int t = 0; t < cases; t++) {
		string s;
		cin >> s;

		int removeCount = 0;
		char atChar = OPPCHAR(s[0]);
		vector<int> streaks;
		int atStreak = 1;
		for (char c: s) {
			if (atChar == c) {
				atStreak += 1;
				removeCount++;
			} else {
				streaks.push_back(atStreak);
				atStreak = 1;
				atChar = OPPCHAR(atChar);
			}
		}
		streaks.push_back(atStreak);
		// sum of streaks
		const unsigned long long sum =
				accumulate(streaks.begin(), streaks.end(), 0,
						   [](int a, int b) { return (a + b) % MOD; }) -
				streaks.size();
		//product of streaks
		int product = accumulate(streaks.begin(), streaks.end(), 1,
								 [](int a, int b) { return (a * b) % MOD; });
		cout << removeCount << " " << (product * factorial(sum)) % MOD << endl;
	}
}