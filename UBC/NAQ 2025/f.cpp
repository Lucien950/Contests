#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>

using namespace std;

static constexpr size_t MAX_N = 5e5;
static array<uint32_t, MAX_N> evals;

static double find_stdev(const double mean, const uint32_t start_win, const uint32_t expected_evals) {
  double out = 0;
  for (uint32_t i = 0; i < expected_evals; i++) {
	out += (evals[start_win + i] - mean) * (evals[start_win + i] - mean);
  }
  return out;
}

int main() {
  uint32_t all_evals, expected_evals;
  cin >> all_evals >> expected_evals;

  for (uint32_t i = 0; i < all_evals; i++)
	cin >> evals[i];

  sort(evals.begin(), evals.begin() + all_evals);

  int64_t sum_win = accumulate(evals.begin(), evals.begin() + expected_evals, 0u);
  double best = find_stdev(static_cast<double>(sum_win) / expected_evals, 0, expected_evals);

  for (uint32_t start_win = 1; start_win < all_evals - expected_evals; start_win++) {
	sum_win -= evals[start_win - 1];
	sum_win += evals[start_win + expected_evals - 1];
	double at = find_stdev(static_cast<double>(sum_win) / expected_evals, start_win, expected_evals);
	best = min(best, at);
  }

  printf("%.10lf", best);
}