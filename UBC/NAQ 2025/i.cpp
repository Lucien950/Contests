#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<uint32_t, 10> team_solves, people_solves;

int main() {
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n; i++)
	cin >> team_solves[i];
  for (uint32_t i = 0; i < n; i++)
	cin >> people_solves[i];

  sort(people_solves.begin(), people_solves.begin() + n, std::greater());

  double out = 0;
  uint64_t team_power = 0;
  for (uint32_t i = 0; i < n; i++) {
	team_power += people_solves[i];
	const double new_avg = static_cast<double>(team_power + team_solves[i]) / static_cast<double>(i + 1);
	out = max(out, new_avg);
  }
  printf("%.10lf\n", out);
}