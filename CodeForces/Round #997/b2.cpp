#include <array>
#include <iostream>

using namespace std;

static array<array<bool, 1001>, 1001> connected;
static array<int, 1000> out;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
	int n;
	cin >> n;
	for (int row = 0; row < n; row++) {
	  string s;
	  cin >> s;
	  for (int col = 0; col < n; col++)
		connected[row][col] = s[col] == '1';
	}
	for (int at = 0; at < n; at++) {
	  int after_count = 0;
	  for (int other = 0; other < n; other++)
		after_count += connected[at][other] ^ at < other;
	  out[after_count] = at + 1;
	}
	for (int i = 0; i < n; i++)
	  cout << out[i] << " ";
	cout << "\n";
  }
}