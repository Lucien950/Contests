#include <iostream>
#include <queue>
#include <ranges>
#include <unordered_set>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t msg_cnt, display_cnt;
  cin >> msg_cnt >> display_cnt;

  unordered_set<uint32_t> displayed;
  queue<uint32_t> screen_rev;
  for (uint32_t i = 0; i < msg_cnt; i++) {
	uint32_t id;
	cin >> id;
	if (displayed.contains(id)) {
	  continue;
	}
	if (screen_rev.size() == display_cnt) {
	  displayed.erase(screen_rev.front());
	  screen_rev.pop(); // pops front
	}
	screen_rev.push(id);
	displayed.insert(id);
  }
  // print screen_rev reversed
  vector<uint32_t> screen;
  screen.reserve(screen_rev.size());
  while (not screen_rev.empty()) {
	screen.push_back(screen_rev.front());
	screen_rev.pop();
  }

  cout << screen.size() << endl;
  for (const unsigned int& it : std::views::reverse(screen)) {
	cout << it << ' ';
  }
  cout << endl;
}