#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int h, w;
	pair<int, int> alice, bob;
	cin >> h >> w >> alice.second >> alice.first >> bob.second >> bob.first;

	const int vert_dist = bob.second - alice.second;
	if (vert_dist <= 0) {
	  cout << "Draw" << endl;
	  continue;
	}

	const int horz_gap = abs(alice.first - bob.first);
	int winner_turns = vert_dist / 2 + 1, loser_turns = vert_dist / 2;

    // calculate wall_dist and possible_winner_name
	int wall_dist;
	std::string possible_winner_name;
	if (vert_dist % 2 == 1) {
	  possible_winner_name = "Alice";
	  if (alice.first > bob.first) {
		wall_dist = bob.first - 1;
	  } else if (alice.first < bob.first) {
		wall_dist = w - bob.first;
	  } else {
		// auto alice win
		wall_dist = INT_MAX;
	  }
	} else {
	  possible_winner_name = "Bob";
	  if (alice.first > bob.first) { // alice left of bob
		wall_dist = w - alice.first; // distance to right wall, drive bob into
	  } else if (alice.first < bob.first) { // alice right of bob
		wall_dist = alice.first - 1; // distance to left wall, drive bob into
	  } else {
		// auto bob win
		wall_dist = INT_MAX;
	  }
	  winner_turns -= 1; // because bob moves second
	}

	if (const bool horizontal_catchable = horz_gap <= winner_turns - min(loser_turns, wall_dist)) {
	  cout << possible_winner_name << endl;
	} else {
	  cout << "Draw" << endl;
	}
  }
}