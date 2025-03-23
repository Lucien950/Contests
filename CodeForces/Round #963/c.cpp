#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int light_count, half_period;
	cin >> light_count >> half_period;
	const unsigned long long period = 2 * half_period;

	unsigned long long i1l = 0, i1r = half_period, i2l = half_period, i2r = period;
	unsigned long long last_start = 0;
	for (int i = 0; i < light_count; i++) {
	  unsigned long long start_time, end_time;
	  cin >> start_time;
	  last_start = max(last_start, start_time);
	  start_time %= period;
	  end_time = (start_time + half_period) % (period);

	  unsigned long long a1l, a1r, a2l, a2r;
	  if (start_time < end_time) {
		a1l = start_time;
		a1r = half_period;
		a2l = half_period;
		a2r = end_time;
	  } else {
		a1l = 0;
		a1r = end_time;
		a2l = start_time;
		a2r = period;
	  }

	  // consolidate
	  i1l = max(i1l, a1l);
	  i1r = min(i1r, a1r);
	  i2l = max(i2l, a2l);
	  i2r = min(i2r, a2r);
	}

	const unsigned long long last_start_period = (last_start / period) * period;
	const bool is_tail_end = (last_start - last_start_period) > half_period;
	const unsigned long long c1 = last_start_period + (is_tail_end * period) + i1l;
	const unsigned long long c2 = last_start_period + i2l;
	const bool c1_valid = i1l < i1r;
	const bool c2_valid = i2l < i2r;
	if (c1_valid && c2_valid) {
	  cout << min(c1, c2) << endl;
	} else if (c1_valid) {
	  cout << c1 << endl;
	} else if (c2_valid) {
	  cout << c2 << endl;
	} else {
	  cout << -1 << endl;
	}
  }
}
