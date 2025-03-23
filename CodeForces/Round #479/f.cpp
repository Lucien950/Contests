#include <iostream>
#include <map>

using namespace std;

// dp[i] is the length of the longest subsequence ending at i
map<int, int> dp;
#define MAX_N (2 * static_cast<size_t>(1e5) + 1)
int a[MAX_N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
	cin >> a[i];
	// note dp[i] defaults to 0
	// note dp[i] contains the existing longest subsequence ending at i
	// note dp[i-1] contains the longest subsequence ending at i-1 at TIME OF ACCESS
	// note that taking i at later time can only improve the result
	dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
  }

  int longest_subseq_length = 0, longest_subseq_end_val = -1;
  for (auto p : dp) {
	if (p.second > longest_subseq_length) {
	  longest_subseq_end_val = p.first;
	  longest_subseq_length = p.second;
	}
  }

  cout << longest_subseq_length << endl;

  // rev engineering the list
  int at_key = longest_subseq_end_val - longest_subseq_length + 1;
  for (int i = 0; at_key <= longest_subseq_end_val; i++) {
	if (i == n + 1) {
	  throw logic_error{"i is too large"};
	}
	if (a[i] == at_key) {
	  cout << i + 1 << " ";
	  at_key++;
	}
  }
  cout << endl;
}