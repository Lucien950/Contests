#include <array>
#include <iostream>
#include <unordered_set>

using namespace std;

static array<int, static_cast<size_t>(2e5)> a, b;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	  cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
	  cin >> b[i];
	}

	unordered_set<int> s1, s2;

	int i;
	for (i = n - 1; i >= 0; --i) {
	  if (a[i] == b[i])
		break;
	  if (s2.contains(a[i]) || s1.contains(b[i]))
		break;
	  if (i - 1 >= 0 && (s2.contains(a[i - 1]) || s1.contains(b[i - 1]))) {
		i--;
		break;
	  }

	  s1.insert(a[i]);
	  s2.insert(b[i]);
	  swap(s1, s2);
	}

	cout << i + 1 << "\n";
  }
  cout << flush;
}