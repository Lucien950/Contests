#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

uint32_t factorial(uint32_t n) {
  uint32_t out = n;
  while (--n)
	out *= n;
  return out;
}

int main() {
  uint32_t n;
  cin >> n;

  vector rolls(n, 0);
  for (int i = 0; i < n; i++) {
	cin >> rolls[i];
  }

  sort(rolls.begin(), rolls.end());
  const uint32_t unique_elements = unique(rolls.begin(), rolls.end()) - rolls.begin();

  const auto total_eventualities = static_cast<uint32_t>(::pow(6, 4 - n));
  if (unique_elements == n) {
	// all unique case
	const uint32_t ash_wins = factorial(6 - n) / factorial(2);
	cout << ash_wins << " " << total_eventualities - ash_wins << endl;
  } else {
	cout << 0 << " " << total_eventualities << endl;
  }
}