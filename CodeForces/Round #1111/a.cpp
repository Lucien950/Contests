#include <array>
#include <iostream>
#include <numeric>
using namespace std;

bool solve(const span<int8_t> a) {
  const int64_t sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum == 0) {
	return true;
  }
  if (sum % 4 != 0) {
	return false;
  }
  // find number of pairs
  int32_t neg_pair = 0, pos_pair = 0;
  for (size_t i = 0; i < a.size() - 1; i++) {
	if (a[i] == a[i + 1]) {
	  if (a[i] > 0)
		pos_pair++;
	  else
		neg_pair++;
	  i += 1;
	}
  }

  if (sum > 0) {
	return pos_pair * 4 >= sum;
  }
  // sum < 0
  return neg_pair * 4 >= -sum;
}

int main() {
  constexpr size_t MAX_N = 100;
  static array<int8_t, MAX_N> a_buf;
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
	  int x;
	  cin >> x;
	  a_buf[i] = static_cast<int8_t>(x);
	}
	const span a(a_buf.data(), n);
	cout << (solve(a) ? "YES" : "NO") << endl;
  }
  cout << flush;
}