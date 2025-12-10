#include <iostream>
#include <unordered_set>

using namespace std;

static unordered_set<int> s;

int main() {
  size_t n, k;
  cin >> n >> k;
  for (size_t i = 0; i < n; i++) {
	int x;
	cin >> x;
	s.insert(x);
  }

  cout << min(s.size(), k) << endl;
}