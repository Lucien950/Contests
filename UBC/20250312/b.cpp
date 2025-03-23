#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

constexpr size_t MAX_L = 1e5 + 1;
static array<int, MAX_L> watchlist;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int num_videos, max_watch_time;
	cin >> num_videos >> max_watch_time;
	for (int i = 0; i < num_videos; i++) {
	  cin >> watchlist[i];
	}

	// int long_videos = 0;
	// for (int i = 0; i < num_videos; i++) {
	//   if (watchlist[i] >= max_watch_time - 1) {
	// 	long_videos++;
	//   }
	// }

	sort(watchlist.begin(), watchlist.begin() + num_videos);
	int l = 0, r = num_videos - 1;
	int matches = 0;
	vector<int> big_videos;
	while (l < r) {
	  if (watchlist[l] + watchlist[r] < max_watch_time) {
		l++;
		r--;
		matches++;
	  } else {
		big_videos.push_back(watchlist[r]);
		r--;
	  }
	}

	if (matches >= big_videos.size()) {
	  cout << (matches - big_videos.size()) / 2 + big_videos.size() << endl;
	} else {
	  size_t ans = big_videos.size(), a = matches, b = big_videos.size() - 1;
	  while (a < b) {
		if (big_videos[b] < max_watch_time) {
		  ans--;
		  a++;
		  b--;
		} else {
		  break;
		}
	  }
	  cout << ans << endl;
	}
  }
}