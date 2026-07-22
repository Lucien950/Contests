#include <cassert>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

constexpr uint64_t MOD = 998'244'353;

enum class step : uint8_t { down, right };
struct path {
  explicit path(const vector<step>& steps) {
	// TODO
  }
};
struct pathgroup {
  void add_path(const path& p) {
	// TODO
  }
};

template <typename T> using Grid = vector<vector<T>>;

void dfs(const Grid<bool>& grid, Grid<pathgroup>& paths, vector<step>& steps_so_far, const uint32_t at_x,
         const uint32_t at_y) {
  if (!grid[at_y][at_x]) {
	return;
  }
  if (at_y == grid.size() - 1 and at_x == grid[0].size() - 1) {
	// we made it to the bottom right corner
	uint32_t x = 0, y = 0;
	const path p{steps_so_far}; // calculate hash once
	for (uint32_t i = 0; not(x == grid[0].size() - 1 and y == grid.size() - 1); i++) {
	  paths[y][x].add_path(p);
	  switch (steps_so_far[i]) {
	  case step::down:
		y += 1;
		break;
	  case step::right:
		x += 1;
		break;
	  default:
		assert(false);
	  }
	}
	return;
  }
  // steps_so_far.push_back(step::down);
  steps_so_far.push_back(step::down);
  dfs(grid, paths, steps_so_far, at_x, at_y + 1);
  steps_so_far.pop_back();
  steps_so_far.push_back(step::right);
  dfs(grid, paths, steps_so_far, at_x + 1, at_y);
  steps_so_far.pop_back();
}

int main() {
  int t;
  cin >> t;
  static Grid<bool> grid{};
  while (t--) {
	uint32_t n, m;
	cin >> n >> m;
	grid.resize(n);
	for (uint32_t i = 0; i < n; i++) {
	  grid[i].resize(m);
	}

	for (uint32_t i = 0; i < n; i++) {
	  for (uint32_t j = 0; j < m; j++) {
		char c;
		cin >> c;
		grid[i][j] = c == '1';
	  }
	}

	Grid<pathgroup> paths;
	{
	  vector<step> psf;
	  dfs(grid, paths, psf, 0, 0);
	}
	unordered_map<pathgroup, uint32_t> path_counts{};
	for (const auto& r : paths) {
	  for (const auto& pg : r) {
		path_counts[pg] += 1;
	  }
	}

	uint64_t out = 0;
	for (const auto& count : path_counts | views::values) {
	  out += 1 << count - 1;
	  out %= MOD;
	}
	cout << out % MOD << endl;
  }
}