#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

array<array<char, 50>, 50> grid;
array<array<bool, 50>, 50> visited;

int height, width;

int64_t dfs(const pair<uint8_t, uint8_t>& at) {
  static array<pair<int8_t, int8_t>, 4> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1),
                                                      make_pair(0, 1)};

  visited[at.first][at.second] = true;
  vector<pair<uint8_t, uint8_t>> next{};
  for (const auto& [dy, dx] : directions) {
	// check out of bounds
	if (at.first + dy < 0 || at.first + dy >= height || at.second + dx < 0 || at.second + dx >= width) {
	  continue;
	}
	if (grid[at.first + dy][at.second + dx] != '.' && !visited[at.first + dy][at.second + dx]) {
	  next.emplace_back(at.first + dy, at.second + dx);
	}
  }

  int64_t a, b;
  switch (grid[at.first][at.second]) {
  case 'P':
  case '#':
	assert(next.size() == 1);
	return dfs(next[0]);
  case '/':
	assert(next.size() == 2);
	a = dfs(next[0]);
	b = dfs(next[1]);
	return max(a, b) / min(a, b);
  case '+':
	assert(next.size() == 2);
	return dfs(next[0]) + dfs(next[1]);
  case '*':
	assert(next.size() == 2);
	return dfs(next[0]) * dfs(next[1]);
  case '-':
	assert(next.size() == 2);
	a = dfs(next[0]);
	b = dfs(next[1]);
	return max(a, b) - min(a, b);
  case '0' ... '9':
	return grid[at.first][at.second] - '0';
  default:
	std::unreachable();
  }
}

int main() {
  cin >> height >> width;
  assert(height <= 50 && width <= 50);

  pair<uint8_t, uint8_t> p;
  for (int i = 0; i < height; i++) {
	for (int j = 0; j < width; j++) {
	  cin >> grid[i][j];
	  if (grid[i][j] == 'P')
		p = {i, j};
	}
  }
  cout << dfs(p) << endl;
}