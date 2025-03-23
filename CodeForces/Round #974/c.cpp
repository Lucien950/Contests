#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	long long pop;
	cin >> pop;
	long long sum_wealth = 0;
	std::vector wealth(pop, 0ll);
	for (int i = 0; i < pop; i++) {
	  cin >> wealth[i];
	  sum_wealth += wealth[i];
	}
	if (pop <= 2) {
	  cout << -1 << endl;
	  continue;
	}
	std::sort(wealth.begin(), wealth.end());
	const size_t i = floor(static_cast<float>(pop) / 2.0f);
	const long long target_average = 2ll * wealth[i];
	const long long out = pop * target_average - sum_wealth + 1;
	cout << max(0ll, out) << endl;
  }
}