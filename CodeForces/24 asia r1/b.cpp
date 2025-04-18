#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<uint32_t, 1000> a{}, b{};

enum class Leading : uint8_t {
  NONE_LEADING,
  A_LEADING,
  B_LEADING,
};

static Leading get_leader(const uint64_t a, const uint64_t b) {
  return a > b ? Leading::A_LEADING : a < b ? Leading::B_LEADING : Leading::NONE_LEADING;
}

int main() {
  while (true) {
	int n;
	cin >> n;
	if (n == 0)
	  break;

	for (int i = 0; i < n; i++)
	  cin >> a[i];
	for (int i = 0; i < n; i++)
	  cin >> b[i];

	uint64_t overtakes = 0;
	Leading prev_leader = get_leader(a[0], b[0]);
	uint64_t a_at = a[0], b_at = b[0];
	for (int i = 1; i < n; i++) {
	  a_at += a[i];
	  b_at += b[i];

	  if (const Leading leader = get_leader(a_at, b_at); leader != Leading::NONE_LEADING && leader != prev_leader) {
		if (prev_leader != Leading::NONE_LEADING)
		  overtakes++;
		prev_leader = leader;
	  }
	}

	cout << overtakes << endl;
  }
}