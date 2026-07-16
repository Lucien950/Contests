#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static constexpr size_t MAX_N = 2e5;

template <typename T> class fenwick {
private:
  size_t n;
  std::vector<T> tree;

public:
  // Initialize tree with a given size and a default minimum value
  explicit fenwick(const size_t n) : n(n), tree(n + 1, std::numeric_limits<T>::lowest()) {}

  /**
   * @brief Updates the index with a new value.
   * Note: Because max is non-invertible, this only works correctly if
   * the new value is greater than or equal to the current value at this index.
   * Time Complexity: O(log N)
   */
  void update(size_t idx, T val) {
	for (; idx <= n; idx += idx & -idx) {
	  tree[idx] = std::max(tree[idx], val);
	}
  }

  /**
   * @brief Queries the maximum value in the prefix range [1, idx].
   * Time Complexity: O(log N)
   */
  [[nodiscard]] T query(const uint64_t _idx) {
	auto idx = static_cast<int64_t>(_idx);
	T max_val = std::numeric_limits<T>::lowest();
	for (; idx > 0; idx -= idx & -idx) {
	  max_val = std::max(max_val, tree[idx]);
	}
	return max_val;
  }
};

int main() {
  int t;
  cin >> t;
  static array<uint32_t, MAX_N> a_buf{};
  // static array<uint64_t, MAX_N> dp{};
  while (t--) {
	size_t n;
	cin >> n;
	span a(a_buf.data(), n);
	for (size_t i = 0; i < n; i++) {
	  cin >> a[i];
	}
	fenwick<uint32_t> dp(n); // query allowed based on j
	                         // index this can be popped, and value
	struct k {
	  size_t leave_index;
	  size_t original_loc;
	  uint32_t value;
	  auto operator<=>(const k& other) const { return leave_index <=> other.leave_index; };
	};
	priority_queue<k, vector<k>, greater<>> pq; // allowed based on i
	for (size_t i = 0; i < n; i++) {
	  // feed pq into dp
	  while (not pq.empty() and pq.top().leave_index <= i) {
		dp.update(pq.top().original_loc + 1, pq.top().value);
		pq.pop();
	  }
	  // solve current
	  const uint32_t v = a[i] + dp.query(i - a[i]);
	  pq.emplace(i + a[i] + 1, i, v);
	}

	uint32_t out = 0;
	while (not pq.empty()) {
	  out = std::max(out, pq.top().value);
	  pq.pop();
	}
	out = max(out, dp.query(n));
	cout << out << '\n';
  }
  cout << flush;
}