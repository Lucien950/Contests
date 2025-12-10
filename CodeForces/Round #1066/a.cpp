#include <array>
#include <iostream>

using namespace std;

static array<int, 101> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	a.fill(0);
	for (int i = 0; i < n; i++) {
	  int x;
	  cin >> x;
	  a[x]++;
	}

	int out = 0;
	for (int i = 0; i <= 100; i++) {
	  if (a[i] == 0)
		continue;
	  if (a[i] > i)
		out += a[i] - i;
	  else if (a[i] < i)
		out += a[i];
	}

	cout << out << "\n";
  }
  cout << flush;
}