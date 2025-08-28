#include <cmath>
#include <cstdint>
#include <iostream>

#define C2

using namespace std;

struct base_cost_out {
  uint64_t cost;
  uint32_t deals_consumed;
  uint32_t max_pow;
};

static base_cost_out base_cost(uint64_t watermelons) {
  uint64_t cost = 0, x = 0;
  uint32_t deals_consumed = 0;
  for (; watermelons > 0; watermelons /= 3, x++) {
	const uint32_t deals = watermelons % 3;
	cost += static_cast<uint64_t>(pow(3ull, x + 1)) * deals;
	if (x > 0 && deals != 0) {
	  cost += x * deals * static_cast<uint64_t>(pow(3ull, x - 1));
	}
	deals_consumed += deals;
  }

  return base_cost_out{cost, deals_consumed, static_cast<uint32_t>(x)};
}

#ifdef C1
static void c1() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t watermelons;
	cin >> watermelons;
	cout << base_cost(watermelons).cost << "\n";
  }
}
#endif

#ifdef C2
static void c2() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t watermelons, deals_left;
	cin >> watermelons >> deals_left;

	const auto [cost, deals_consumed, max_pow] = base_cost(watermelons);
	uint64_t final_cost = cost;
	if (deals_consumed > deals_left) {
	  cout << "-1\n";
	  continue;
	}
	deals_left -= deals_consumed;

	uint32_t carry_over = 0;
	for (uint32_t at_pow = max_pow; deals_left >= 2 && at_pow > 0; at_pow--) {
	  uint32_t demotes_left = watermelons / static_cast<uint32_t>(pow(3.0, at_pow)) % 3, new_carry_over = 0;

	  const auto cost_savings = static_cast<uint64_t>(pow(3.0, at_pow - 1));

	  // there's probably some clever math way of figuring this out faster
	  while ((demotes_left > 0 || carry_over > 0) && deals_left >= 2) { // in particular deals_left - 2 >= 0
		final_cost -= cost_savings;
		deals_left -= 2;

		if (demotes_left > 0)
		  demotes_left -= 1;
		else
		  carry_over -= 1;
		new_carry_over += 3;
	  }

	  carry_over = new_carry_over;
	}

	cout << final_cost << "\n";
  }
}
#endif

int main() {
#ifdef C1
  c1();
#endif
#ifdef C2
  c2();
#endif
}