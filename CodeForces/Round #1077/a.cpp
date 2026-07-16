#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

static vector<int> a;

int main() {
  int t;
  cin >> t;
  a.reserve(100);
  while (t--) {
	int n;
	cin >> n;
	a.clear();

	int at = 1;
	for (int i = 0; i < n; i++) {
	  a.push_back(at);
	  if (i % 2 == 0) {
		at += n - i - 1;
	  } else {
		at -= n - i - 1;
	  }
	}

	for (const int x : ranges::reverse_view(a)) {
	  cout << x << ' ';
	}
	cout << '\n';
  }
  cout << flush;
}