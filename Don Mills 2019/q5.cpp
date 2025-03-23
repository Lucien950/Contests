#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum class color { red = 1, blue = 2 };

struct point {
  pair<int, int> coords;
  int index{};
  color c{};

  bool operator<(const point& b) const { return coords < b.coords; }
};

int main() {
  int n;
  cin >> n;

  vector<point> pts(n);
  for (int i = 0; i < n; i++) {
	cin >> pts[i].coords.first >> pts[i].coords.second;
	int c_num;
	cin >> c_num;
	switch (c_num) {
	case 1:
	  pts[i].c = color::red;
	  break;
	case 2:
	  pts[i].c = color::blue;
	  break;
	default:
	  return EXIT_FAILURE;
	}

	pts[i].index = i + 1;
  }
  std::sort(pts.begin(), pts.end());

  for (int i = 0; i < n - 2; i++) {
	const point &a = pts[i], b = pts[i + 1], c = pts[i + 2];
	if (!(a.c != b.c || a.c != c.c)) // if a's colour matches b and c's colours (i.e. all their colours are the same)
	  continue;
	cout << a.index << " " << b.index << " " << c.index << endl;
	return EXIT_SUCCESS;
  }
  cout << -1 << endl;
  return EXIT_SUCCESS;
}