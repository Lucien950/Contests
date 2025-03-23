#include <array>
#include <iostream>
#include <unordered_map>
using namespace std;

static array<array<int, 700>, 700> colors;

static bool in_bounds(const int rows, const int cols, const int row, const int col) {
  return row >= 0 && row < rows && col >= 0 && col < cols;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int rows, cols;
	cin >> rows >> cols;
	for (int row = 0; row < rows; row++)
	  for (int col = 0; col < cols; col++)
		cin >> colors[row][col];
	unordered_map<int, int> cock;
	for (int row = 0; row < rows; row++) {
	  for (int col = 0; col < cols; col++) {
		int color = colors[row][col];
		const bool has_neighbour_same_col = in_bounds(rows, cols, row - 1, col) && color == colors[row - 1][col] ||
		                                    in_bounds(rows, cols, row + 1, col) && color == colors[row + 1][col] ||
		                                    in_bounds(rows, cols, row, col - 1) && color == colors[row][col - 1] ||
		                                    in_bounds(rows, cols, row, col + 1) && color == colors[row][col + 1];
		cock[color] = max(1 + has_neighbour_same_col, cock[color]);
	  }
	}
	if (cock.size() == 1) {
	  cout << 0 << endl;
	  continue;
	}
	int max_cnt = 0, sum = 0;
	for (const auto [_colour, cnt] : cock) {
	  max_cnt = max(max_cnt, cnt);
	  sum += cnt;
	}
	cout << sum - max_cnt << endl;
  }
}