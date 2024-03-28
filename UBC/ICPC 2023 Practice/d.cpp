#include <iostream>

using namespace std;

int main() {
  int game_count;
  cin >> game_count;
  while (game_count--) {
	int lower_bound = 1, higher_bound = 1000;
	while (true) {
	  const int guess = (lower_bound + higher_bound) / 2;
	  cout << guess << endl;
	  string feedback;
	  cin >> feedback;
	  if (feedback == "lower") {
		higher_bound = guess - 1;
	  } else if (feedback == "higher") {
		lower_bound = guess + 1;
	  } else {
		// correct, move on
		break;
	  }
	}
  }
}