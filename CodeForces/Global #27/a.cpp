#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t rows, cols, start_row, start_col;
	cin >> rows >> cols >> start_row >> start_col;

	const uint64_t shifters = cols - start_col, full_rows = rows - start_row, full_row_shifter_count = cols - 1,
	               full_row_rounders = cols - 1 + 1;
	cout << shifters + full_rows * (full_row_shifter_count * 1 + 1 * full_row_rounders) << endl;
  }
}