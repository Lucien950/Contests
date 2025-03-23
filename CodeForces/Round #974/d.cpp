#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int days, stay_len, job_count;
	cin >> days >> stay_len >> job_count;

	std::vector<int> psa(days + 2, 0);
	for (int i = 0; i < job_count; i++) {
	  int left, right;
	  cin >> left >> right;
	  psa[max(0, left - stay_len + 1)]++;
	  psa[right + 1]--;
	}

	int brother_visit_start_day = 0, brother_visit_jobs = INT_MIN, mother_visit_start_day = 0,
	    mother_visit_jobs = INT_MAX;
	int ongoing_jobs = 0;
	for (int win_start_day = 1; win_start_day <= days - stay_len + 1; win_start_day++) {
	  // update ongoing jobs
	  ongoing_jobs += psa[win_start_day];
	  // update brother and mother visit days
	  if (ongoing_jobs > brother_visit_jobs) {
		brother_visit_start_day = win_start_day;
		brother_visit_jobs = ongoing_jobs;
	  }
	  if (ongoing_jobs < mother_visit_jobs) {
		mother_visit_start_day = win_start_day;
		mother_visit_jobs = ongoing_jobs;
	  }
	}
	cout << brother_visit_start_day << " " << mother_visit_start_day << endl;
  }
}