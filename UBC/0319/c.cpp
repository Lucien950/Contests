#include <iostream>

using namespace std;

int main() {
  int pieces;
  cin >> pieces;

  for (int i = 0; i < pieces; i++) {
	char piece;
	int length, pos;
	cin >> piece >> length >> pos;

	switch (piece) {
	case '|':
	  break;
	case '-':
	  break;
	default:
	  throw std::invalid_argument("Invalid piece");
	}
  }
}