#include <iostream>
using namespace std;
int main() {
  int p1_inhole, p1_onboard;
  int p2_inhole, p2_onboard;
  cin >> p1_inhole >> p1_onboard >> p2_inhole >> p2_onboard;
  const int p1_points = p1_inhole * 3 + p1_onboard, p2_points = p2_inhole * 3 + p2_onboard;
  if (p1_points > p2_points) {
	cout << 1 << " " << p1_points - p2_points << endl;
  } else if (p2_points > p1_points) {
	cout << 2 << " " << p2_points - p1_points << endl;
  } else {
	cout << "NO SCORE" << endl;
  }
}