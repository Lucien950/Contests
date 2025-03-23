#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// static constexpr size_t MAX_NODES = 1e6 + 1;
// class bitset final {
//   // layout in array is 63-0, 127-64, etc.
//   std::array<uint64_t, (MAX_NODES + 64 - 1) / 64> data{}; // length is ceil(MAX_NODES/64) approx 2^14 < 2^16
//
//   struct chunk_bit {
// 	uint16_t chunk;
// 	uint8_t bit;
// 	chunk_bit(const uint16_t i_chunk, const uint8_t i_bit) : chunk(i_chunk), bit(i_bit) {}
// 	auto operator<=>(const chunk_bit& rhs) const {
// 	  if (chunk != rhs.chunk)
// 		return chunk <=> rhs.chunk;
// 	  return bit <=> rhs.bit;
// 	}
//   };
//   chunk_bit leftmost_chunkbit{0, 0};
//   [[nodiscard]] uint8_t get_leftmost_bit_in_chunk(const uint16_t chunk) const {
// 	if (data[chunk] == 0)
// 	  return 0;
// 	return 63 - static_cast<uint8_t>(__builtin_clzll(data[chunk]));
//   }
//
// public:
//   explicit bitset() = default;
//
//   void add_two_to_the(const uint32_t d) {
// 	uint16_t chunk = d / 64;
// 	// execute the addition
// 	uint64_t to_add = 1 << d % 64;
// 	bool carry;
// 	do {
// 	  carry = data[chunk] > UINT64_MAX - to_add;
// 	  data[chunk] += to_add;
//
// 	  // update for next iteration
// 	  to_add = 1;
// 	  chunk++;
// 	} while (carry);
//
// 	// undo last update for next iteration
// 	chunk--;
// 	leftmost_chunkbit = max(leftmost_chunkbit, chunk_bit{chunk, get_leftmost_bit_in_chunk(chunk)});
//   }
//
//   [[nodiscard]] uint32_t ceil_log2() const {
// 	for (auto i_chunk = static_cast<int32_t>(leftmost_chunkbit.chunk); i_chunk >= 0; --i_chunk) {
// 	  uint64_t chunk = data[i_chunk];
// 	  // revert the leftmost bit
// 	  if (i_chunk == static_cast<int32_t>(leftmost_chunkbit.chunk)) // first iteration
// 		chunk ^= 1 << leftmost_chunkbit.bit;
// 	  if (chunk > 0)
// 		// if there are 1s in chunk
// 		return leftmost_chunkbit.chunk * 64 + leftmost_chunkbit.bit + 1;
// 	}
// 	return leftmost_chunkbit.chunk * 64 + leftmost_chunkbit.bit;
//   }
// };

/**
 * @note that the depth can be up to 10^6 approx 2^20 < 2^32
 */
static uint32_t get_shortest_btree(const uint32_t at, const map<uint32_t, vector<uint32_t>>& children) {
  if (!children.contains(at))
	return 0;

  vector<uint32_t> depths;
  uint32_t height_required = 0; // height_required = max(d_c)
  for (const uint32_t child : children.at(at)) {
	const uint32_t d = get_shortest_btree(child, children);
	depths.push_back(d);
	height_required = max(height_required, d);
  }
  ranges::sort(depths);
  uint32_t a = 0, b = 0;
  for (const auto j : depths) {
	if (b == j)
	  a++;
	else {
	  const int c = 1 << min(30u, j - b);
	  a = (a + c - 1) / c;
	  b = j;
	  a++;
	}
  }
  const uint32_t width_constraint = b + 32 - __builtin_clz(a - 1);
  return max(width_constraint, height_required + 1);
}

int main() {
  assert(sizeof(uint64_t) == 64 / 8);
  assert(sizeof(uint32_t) == 32 / 8);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	uint32_t n;
	cin >> n;
	map<uint32_t, vector<uint32_t>> children;
	for (uint32_t i = 2; i < n + 1; i++) {
	  uint32_t p_i; // parent of vertex i
	  cin >> p_i;
	  children[p_i].push_back(i);
	}
	cout << get_shortest_btree(1, children) << "\n";
  }
  cout << endl;
}