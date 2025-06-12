#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
  static long long distributeCandies(const int n, const int limit) {
	long long total = 0;
	for (int first = 0; first <= min(limit, n); first++) {
	  const long long ub = min(n - first, limit);
	  const long long lb = max(0, n - first - limit);
	  const long long theory = ub - lb + 1;
	  total += max(0ll, theory);
	}
	return total;
  }
};

int main() { cout << Solution::distributeCandies(5, 2) << endl; }