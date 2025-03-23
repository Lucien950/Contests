#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int len, piece_count;
	cin >> len >> piece_count;
	int sum = 0, largest_piece = INT_MIN;
	for (int i = 0; i < piece_count; i++) {
	  int piece;
	  cin >> piece;
	  largest_piece = std::max(largest_piece, piece);
	  sum += 2 * piece - 1;
	}
	sum -= 2 * largest_piece - 1;
	cout << sum << endl;
  }
}