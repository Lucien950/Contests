#include <array>
#include <iostream>

using namespace std;
static array<int, 51> freq{};

int main() {
  int t;
  cin >> t;
  while (t--) {
	freq.fill(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  int s_i;
	  cin >> s_i;
	  freq[s_i]++;
	}

	int score = 0;
	const int mexes = min(freq[0], freq[1]);
	freq[0] -= mexes;
	freq[1] -= mexes;
	score += 2 * mexes;
	score += freq[0]; // mex all remaining 0s to 1s
	for (int i = 1; i <= 50; i++) {
	  score += freq[i] * i;
	}
	cout << score << "\n";
  }
  cout << flush;
}