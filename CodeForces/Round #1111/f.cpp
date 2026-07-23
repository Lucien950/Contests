#include <algorithm>
#include <array>
#include <cassert>
#include <concepts>
#include <iostream>
#include <limits>
#include <random>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

constexpr uint32_t MOD = 998'244'353; // 2 bits away from 32-bit integer overflow

template <integral T, T mod> class modder {
  static_assert(mod > 0, "mod must be positive");
  static_assert(MOD * 2 < numeric_limits<T>::max()); // this makes sure that addition (and sub?) doesn't overflow

public:
  T val;

  modder operator+(const modder& b) const { return {this->val + b.val}; }
  modder operator-(const modder& b) const { return {this->val - b.val + mod}; }
  modder operator*(const modder& b) const {
	const __uint128_t out =
	    static_cast<__uint128_t>(val) * static_cast<__uint128_t>(b.val) % static_cast<__uint128_t>(mod);
	static_assert(sizeof(out) == 16, "out must be 128 bits");
	return {static_cast<T>(out)};
  }
  modder& operator+=(const modder& b) {
	val = (val + b.val) % mod;
	return *this;
  }

  modder() = default;
  // ReSharper disable once CppNonExplicitConvertingConstructor
  constexpr modder(const T a) { val = (a + mod) % mod; }
};
static constexpr modder<uint64_t, MOD> zero{0};

template <typename T> class Grid : public vector<vector<T>> {
public:
  void resize(const size_t n, const size_t m) {
	vector<vector<T>>::resize(n);
	for (auto& row : *this) {
	  row.resize(m);
	}
  }
};

template <typename T> class RandomGrid : public Grid<T> {
public:
  void resize(const size_t n, const size_t m) {
	const size_t old_n = Grid<T>::size(), old_m = old_n > 0 ? Grid<T>::at(0).size() : 0;
	Grid<T>::resize(n, m);
	random_device rd;
	mt19937_64 gen(rd());
	// fill with random values
	constexpr uint64_t MM = 2000000000;

	if (old_m < m) {
	  for (size_t i = 0; i < min(n, old_n); i++) {
		for (size_t j = old_m; j < m; ++j) {
		  uint64_t rand_val = gen() % MM + 1;
		  Grid<T>::at(i).at(j) = rand_val;
		}
	  }
	}
	if (old_n < n) {
	  for (size_t i = old_n; i < n; ++i) {
		for (size_t j = 0; j < m; j++) {
		  uint64_t rand_val = gen() % MM + 1;
		  Grid<T>::at(i).at(j) = rand_val;
		}
	  }
	}
  }
};

int main() {
  int t;
  cin >> t;
  Grid<bool> grid{};
  Grid<modder<uint64_t, MOD>> dp1, dp2;
  RandomGrid<uint64_t> h, v;

  static array<uint32_t, 1000010> pw2{};
  pw2[0] = 1;
  for (int i = 1; i < 1000010; i++)
	pw2[i] = pw2[i - 1] * 2 % MOD;

  while (t--) {
	size_t n, m;
	cin >> n >> m;
	grid.resize(n, m);
	dp1.resize(n, m);
	dp2.resize(n, m);
	h.resize(n, m);
	v.resize(n, m);

	for (size_t i = 0; i < n; i++) {
	  for (size_t j = 0; j < m; j++) {
		char c;
		cin >> c;
		grid[i][j] = c == '1';
	  }
	}

	for (size_t i = 0; i < n; i++) {
	  ranges::fill(dp1[i], zero);
	  ranges::fill(dp2[i], zero);
	}
	dp1[0][0] = dp2[n - 1][m - 1] = modder<uint64_t, MOD>(1);

	// forward pass on dp1
	for (size_t i = 0; i < n; i++) {
	  for (size_t j = 0; j < m; j++) {
		if (not grid[i][j])
		  continue;
		if (i > 0)
		  dp1[i][j] += dp1[i - 1][j] * modder<uint64_t, MOD>{v[i - 1][j]};
		if (j > 0)
		  dp1[i][j] += dp1[i][j - 1] * modder<uint64_t, MOD>{h[i][j - 1]};
	  }
	}
	// backwards pass on dp2
	for (int64_t i = static_cast<int64_t>(n) - 1; i >= 0; i--) {
	  for (int64_t j = static_cast<int64_t>(m) - 1; j >= 0; j--) {
		if (not grid[i][j])
		  continue;
		if (i < static_cast<int64_t>(n) - 1)
		  dp2[i][j] += dp2[i + 1][j] * modder<uint64_t, MOD>{v[i][j]};
		if (j < static_cast<int64_t>(m) - 1)
		  dp2[i][j] += dp2[i][j + 1] * modder<uint64_t, MOD>{h[i][j]};
	  }
	}

	// because you need to sub 1 from this :((((
	unordered_map<uint64_t, int64_t> path_counts{};
	for (size_t i = 0; i < n; i++) {
	  for (size_t j = 0; j < m; j++) {
		path_counts[(dp1[i][j] * dp2[i][j]).val]++;
	  }
	}

	modder<int64_t, MOD> out{0};
	for (const int64_t& count : path_counts | views::values) {
	  out += pw2[count] - 1ll;
	}
	cout << out.val << endl;
  }
}