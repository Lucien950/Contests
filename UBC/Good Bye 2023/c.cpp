#include <iostream>

using namespace std;

int main() {
#define int long long
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	int a[n];
	int sum_first_k[n];
	int odd_count_first_k[n];
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	  sum_first_k[i] = a[i] + (i - 1 >= 0 ? sum_first_k[i - 1] : 0);
	  odd_count_first_k[i] = (i - 1 >= 0 ? odd_count_first_k[i - 1] : 0) + (a[i] % 2 == 1 ? 1 : 0);
	}

	for (int k = 0; k < n; k++) {
	  if (k == 0) {
		cout << sum_first_k[k] << " ";
		continue;
	  }
	  const int current_odd_count = odd_count_first_k[k];
	  const int misha_then_olya_subs = current_odd_count / 3, scraps_subs = current_odd_count % 3 == 1 ? 1 : 0;
	  const int total_subs = misha_then_olya_subs + scraps_subs;
	  cout << sum_first_k[k] - total_subs << " ";
	}

	cout << endl;
  }
}