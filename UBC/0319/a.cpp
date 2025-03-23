// #include <algorithm>
// #include <cstdint>
#include <array>
#include <iostream>
using namespace std;

static array<int, static_cast<size_t>(1e5 + 1)> temps;

static bool possible_temp(const int check_temp, const int coat_days,
                          const array<int, static_cast<size_t>(1e5 + 1)>& temps, const int total_days) {
  int streak = 0;
  for (int i = 0; i < total_days; i++) {
	if (temps[i] < check_temp)
	  streak++;
	else
	  streak = 0;
	if (streak > coat_days)
	  return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int coat_days, total_days;
  cin >> coat_days >> total_days;

  for (int i = 0; i < total_days; i++)
	cin >> temps[i];

  int l = -50, r = 50;
  while (l < r) {
	if (const int mid = (l + r - 1) / 2 + 1; possible_temp(mid, coat_days, temps, total_days)) {
	  l = mid;
	} else {
	  r = mid - 1;
	}
  }
  cout << r << '\n';

  //  for (int i = 50; i >= -50; i--) {
  // if (possible_temp(i, coat_days, temps, total_days)) {
  //   cout << i << '\n';
  //   return 0;
  // }
  //  }
  //  return 1;
}