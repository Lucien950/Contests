#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template <auto f, typename T>
concept segtree_fcn = requires(const T& a, const T& b, const uint32_t l) {
  { f(a, b, l) } -> std::same_as<T>;
};

template <typename T, auto f>
  requires segtree_fcn<f, T> && default_initializable<T>
struct Tree {
  vector<T> s;
  size_t n; // number of leaves
  uint32_t max_level;
  explicit Tree(const size_t n, const T def = {}) : s(2 * n, def), n(n), max_level(32 - __builtin_clz(n - 1)) {}
  void update(size_t pos, const T val) {
	s[pos += n] = val;
	uint32_t l = 1; // start at 2^1 = 2
	for (; pos >>= 1; l++)
	  s[pos] = f(s[pos << 1], s[pos << 1 | 1], 1 << l);
  }

  [[nodiscard]] T query(size_t b, size_t e) const { // query [ b , e)
	T ra = {}, rb = {};
	b += n;
	e += n;
	uint32_t l = 0;
	for (; b < e; b >>= 1, e >>= 1, l++) {
	  if (b & 0b1) // if the last digit of b is a 1
		ra = f(ra, s[b++], 1 << l);
	  if (e & 0b1) // if the last digit of e is a 1
		rb = f(s[--e], rb, 1 << l);
	}
	// maybe l+1?
	return f(ra, rb, 1 << l);
  }
  [[nodiscard]] const T& root() const { return s[1]; }
};

struct node {
  uint32_t min = numeric_limits<uint32_t>::max();
  uint32_t max = 0;
  uint32_t k = 0;
  node(const uint32_t _max, const uint32_t _min) : min(_min), max(_max) {}
  node(const uint32_t max, const uint32_t min, const uint32_t k) : min(min), max(max), k(k) {};
  node() = default;
};
node fcn(const node& a, const node& b, const uint32_t len) {
  uint32_t new_k = max(a.k, b.k);
  if (a.max > b.min) {
	new_k = max(new_k, len / 2);
  }
  return {max(a.max, b.max), min(a.min, b.min), new_k};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
	uint32_t n, q;
	cin >> n >> q;
	uint32_t N = 1; // N = min {k|2^k >= n}
	while (N < n)
	  N *= 2;

	Tree<node, fcn> segtree(N, {numeric_limits<uint32_t>::max(), numeric_limits<uint32_t>::max(), 0});
	for (size_t i = 0; i < n; i++) {
	  uint32_t a;
	  cin >> a;
	  segtree.update(i, {a, a});
	}
	cout << segtree.root().k << '\n';
	for (size_t i = 0; i < q; i++) {
	  uint32_t index, reset_value;
	  cin >> index >> reset_value;
	  segtree.update(index, {reset_value, reset_value});
	  cout << segtree.root().k << '\n';
	}
  }
  cout << flush;
}