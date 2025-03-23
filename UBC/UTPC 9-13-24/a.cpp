#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  pair<int, int> curpos;
  cin >> curpos.first >> curpos.second;

  pair<int, int> closest_point;
  double closest_distance = std::numeric_limits<double>::max();
  for (int i = 0; i < n; i++) {
	pair<int, int> new_pos;
	cin >> new_pos.first >> new_pos.second;
	if (const double cur_dist = pow(new_pos.first - curpos.first, 2) + pow(new_pos.second - curpos.second, 2);
	    cur_dist < closest_distance || (cur_dist == closest_distance && new_pos.first < closest_point.first)) {
	  closest_distance = cur_dist;
	  closest_point = new_pos;
	}
  }
  cout << closest_point.first << " " << closest_point.second << endl;
}