// #include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int m;
  cin >> m;
  std::unordered_map<int64_t, unordered_map<int64_t, bool>> seen;
  int64_t x = 0, y = 0;
  seen[x][y] = true;
  unsigned long long out = 0;
  for (int i = 0; i < m; i++) {
	char dd;
	cin >> dd;
	int s;
	cin >> s;
	assert(0 <= s && s <= 20);
	switch (dd) {
	case 'N':
	  for (int j = 0; j < s; j++) {
		y++;
		if (seen[x][y]) {
		  out++;
		}
		seen[x][y] = true;
	  }
	  break;
	case 'S':
	  for (int j = 0; j < s; j++) {
		y--;
		if (seen[x][y]) {
		  out++;
		}
		seen[x][y] = true;
	  }
	  break;
	case 'E':
	  for (int j = 0; j < s; j++) {
		x++;
		if (seen[x][y]) {
		  out++;
		}
		seen[x][y] = true;
	  }
	  break;
	case 'W':
	  for (int j = 0; j < s; j++) {
		x--;
		if (seen[x][y]) {
		  out++;
		}
		seen[x][y] = true;
	  }
	  break;
	default:;
	}
  }
  cout << out << endl;
}