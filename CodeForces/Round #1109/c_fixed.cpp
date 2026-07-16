#include <bits/stdc++.h>
using namespace std;

template <typename T> struct DSU {
  vector<T> p{}, r{};
  explicit DSU(size_t n) {
	p.resize(n);
	r.resize(n);
	fill(r.begin(), r.end(), 0);
	iota(p.begin(), p.begin() + n, 0);
  }
  T find(T x) { return p[x] == x ? x : p[x] = find(p[x]); }
  void unite(T a, T b) {
	a = find(a);
	b = find(b);
	if (a == b)
	  return;
	if (r[a] < r[b])
	  swap(a, b);
	p[b] = a;
	if (r[a] == r[b])
	  ++r[a];
  }
};

static constexpr size_t MAX_N = 2e5;
static array<uint32_t, MAX_N> a_buf{};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  if (!(cin >> tt))
	return 0;
  while (tt--) {
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
	  cin >> a_buf[i];
	  --a_buf[i];
	}
	DSU<uint32_t> d(n);
	for (int i = 0; i < n; i++) {
	  if (i + x < n)
		d.unite(i, i + x);
	  if (i + y < n)
		d.unite(i, i + y);
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
	  if (d.find(i) != d.find(a_buf[i])) {
		ok = false;
		break;
	  }
	}
	cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
