#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	unsigned long long sum = 0;
	size_t zero_count = 0;
	for (size_t i = 0; i < n; i++) {
	  int b;
	  cin >> b;
	  sum += b;
	  zero_count += b == 0;
	}
	cout << min(sum - n + zero_count, n - 1) - zero_count + 1 << endl;
  }
}