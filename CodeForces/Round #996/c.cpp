#include <array>
#include <iostream>
using namespace std;

static array<array<long long, 1000>, 1000> a;
static array<int, 1000> col_deg_freedom;
static array<int, 1000> row_deg_freedom;

static long long row_sum(const int row, const int col_count) {
  long long out = 0;
  for (int col = 0; col < col_count; col++) {
	out += a[row][col];
  }
  return out;
}

static long long col_sum(const int col, const int row_count) {
  long long out = 0;
  for (int row = 0; row < row_count; row++) {
	out += a[row][col];
  }
  return out;
}

struct point {
  int row;
  int col;
  constexpr explicit point(const int col, const int row) : row(row), col(col) {};
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	int row_count, col_count;
	string path_string;
	cin >> row_count >> col_count >> path_string;

	// coordinates are (row, col)
	// each coordinate has an altitude
	for (int row = 0; row < row_count; row++) {
	  for (int col = 0; col < col_count; col++) {
		cin >> a[row][col];
	  }
	}
	std::fill_n(row_deg_freedom.begin(), row_count, 0);
	std::fill_n(col_deg_freedom.begin(), col_count, 0);

	{
	  point at{0, 0};
	  row_deg_freedom[0]++;
	  col_deg_freedom[0]++;
	  for (const char c : path_string) {
		if (c == 'D') {
		  at.row++;
		} else if (c == 'R') {
		  at.col++;
		} else {
		  throw std::invalid_argument("invalid path move");
		}
		row_deg_freedom[at.row]++;
		col_deg_freedom[at.col]++;
	  }
	}
	constexpr long long target_sum = 0;
	{
	  point at{0, 0};
	  if (row_deg_freedom[0] == 1) {
		a[0][0] = target_sum - row_sum(0, col_count);
	  } else if (col_deg_freedom[0] == 1) {
		a[0][0] = target_sum - col_sum(0, row_count);
	  } else {
		throw std::runtime_error("unexpected behaviour");
	  }
	  col_deg_freedom[0]--;
	  row_deg_freedom[0]--;

	  for (const char c : path_string) {
		if (c == 'D') {
		  at.row++;
		} else if (c == 'R') {
		  at.col++;
		} else {
		  throw std::invalid_argument("invalid path move");
		}
		if (row_deg_freedom[at.row] == 1) {
		  // force a[at] + row_sum = target
		  a[at.row][at.col] = target_sum - row_sum(at.row, col_count);
		} else if (col_deg_freedom[at.col] == 1) {
		  a[at.row][at.col] = target_sum - col_sum(at.col, row_count);
		} else {
		  throw std::runtime_error("unexpected behaviour");
		}
		col_deg_freedom[at.col]--;
		row_deg_freedom[at.row]--;
	  }
	}

	// output altitudes
	for (int row = 0; row < row_count; row++) {
	  for (int col = 0; col < col_count; col++) {
		cout << a[row][col] << " ";
	  }
	  cout << "\n";
	}

#ifndef ONLINE_JUDGE
	cout << "DEBUG MESSAGES" << endl << "target sum " << target_sum << endl;
	for (int row = 0; row < row_count; row++) {
	  if (row_sum(row, col_count) != target_sum) {
		cout << "fail on row " << row << endl;
	  }
	}
	for (int col = 0; col < col_count; col++) {
	  if (col_sum(col, row_count) != target_sum) {
		cout << "fail on col " << col << " with sum " << col_sum(col, row_count) << endl;
	  }
	}
	cout << "=============" << endl;
#endif
  }
  cout << endl;
}