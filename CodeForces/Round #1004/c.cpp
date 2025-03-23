#include <iostream>
using namespace std;

static int down_to_7(const int n) { return (n - 7 + 10) % 10; }
static int up_to_7(const int n) { return (7 - n + 10) % 10; }

static int solve(const int n) {
  const string s = to_string(n);
  if (s.find('7') != string::npos)
	return 0;
  down_to_7(n % 10);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	cout << solve(n) << endl;
  }
}