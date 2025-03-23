#include <array>
#include <iostream>
#include <vector>

using namespace std;

static array<array<bool, 1001>, 1001> connected;

static array<int, 1000> out;

void solve(const int left_most_out_pos, vector<int>& to_sort) {
  const int at = to_sort[0];
  to_sort.erase(to_sort.begin());

  if (to_sort.empty()) {
	out[left_most_out_pos] = at;
	return;
  }

  vector<int> left;
  vector<int> right;

  for (const int& other : to_sort) {
	if (connected[at][other]) {
	  right.push_back(other);
	} else {
	  left.push_back(other);
	}
  }

  const size_t left_offset = left.size();
  out[left_offset + left_most_out_pos] = at;
  if (!left.empty())
	solve(left_most_out_pos, left);
  if (!right.empty())
	solve(left_most_out_pos + static_cast<int>(left_offset + 1), right);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	for (int row = 0; row < n; row++) {
	  string s;
	  cin >> s;
	  for (int col = 0; col < n; col++) {
		connected[row + 1][col + 1] = s[col] == '1';
	  }
	}

	vector<int> use;
	use.reserve(n);
	for (int i = 1; i <= n; i++) {
	  use.push_back(i);
	}
	solve(0, use);

	for (int i = 0; i < n; i++) {
	  cout << out[i] << " ";
	}
	cout << endl;
  }
}