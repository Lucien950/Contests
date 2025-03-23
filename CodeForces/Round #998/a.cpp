#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	std::unordered_map<int, int> q;
	int a, b, d, e;
	cin >> a >> b >> d >> e;
	q[a + b]++;
	q[d - b]++;
	q[e - d]++;

	int m = INT_MIN;
	for (const auto& [_fst, snd] : q) {
	  m = max(m, snd);
	}
	cout << m << endl;
  }
}