#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

const string directions[] = {"down", "right", "left", "up"};
string get_opposite_direction(const string& d) {
  if (d == "up")
	return "down";
  if (d == "down")
	return "up";
  if (d == "right")
	return "left";
  if (d == "left")
	return "right";
  throw std::exception();
}

pair<int, int> get_new_loc(const pair<int, int>& at, const string& d) {
  if (d == "up")
	return {at.first, at.second - 1};
  if (d == "down")
	return {at.first, at.second + 1};
  if (d == "right")
	return {at.first + 1, at.second};
  if (d == "left")
	return {at.first - 1, at.second};
  throw std::exception();
}

string make_move(const string& m) {
  string feedback;
  cout << m << endl;
  cin >> feedback;
  return feedback;
}

bool in_current_path[201][201];

bool explore(const pair<int, int>& at) { //, const string& forbidden_direction = "") {
  in_current_path[at.second][at.first] = true;
  for (auto& direction : directions) {
	const pair<int, int> newLoc = get_new_loc(at, direction);
	// the way to return to the current cell after the current has been executed
	const string nextReturnMove = get_opposite_direction(direction);
	if (in_current_path[newLoc.second][newLoc.first]) // || direction == forbidden_direction) // no cycles
	  continue;
	const string feedback = make_move(direction);
	if (feedback == "wall")
	  continue;
	if (feedback == "solved")
	  return true;
	assert(feedback == "ok");
	if (explore(newLoc))
	  return true;
	// backtrack
	assert(make_move(nextReturnMove) == "ok");
  }
  // in_current_path[at.second][at.first] = false;
  return false;
}

int main() {
  memset(in_current_path, false, sizeof(in_current_path));
  if (const bool found_way_out = explore({101, 101}); !found_way_out) {
	cout << "no way out" << endl;
  }
}