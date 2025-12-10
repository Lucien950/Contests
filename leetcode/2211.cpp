#include <ranges>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
  static int countCollisions(const string& directions) {
	int out = directions.size();

	bool shooting = true;
	for (const char c : directions) {
	  switch (c) {
	  case 'L':
		if (shooting)
		  out--;
		break;
	  case 'R':
		shooting = false;
		break;
	  case 'S':
		shooting = false;
		out--;
		break;
	  default:
		unreachable();
	  }
	}

	for (const char c : directions | views::reverse) {
	  switch (c) {
	  case 'R':
		if (shooting)
		  out--;
		break;
	  case 'L':
	  case 'S':
		break;
	  default:
		unreachable();
	  }
	}

	return out;
  }
};