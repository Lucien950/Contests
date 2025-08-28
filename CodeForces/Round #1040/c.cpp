#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

struct seg_info {
  int start;
  int end;
  int pos;
  strong_ordering operator<=>(const seg_info& other) const { return start <=> other.start; }
};
static array<seg_info, 3000> segments{};

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> segments[i].start >> segments[i].end;
	  segments[i].pos = i;
	}
	sort(segments.begin(), segments.begin() + n);

	vector<uint32_t> out;
	optional<int> seg_end = nullopt;
	for (auto at = segments.begin(), end = segments.begin() + n; at != end; ++at) {
	  if (!seg_end.has_value() || at->end > seg_end.value()) {
		out.push_back(at->pos + 1);
		seg_end = at->end;
	  }
	}

	cout << out.size() << "\n";
	for (const uint32_t o : out) {
	  cout << o << " ";
	}
	cout << "\n";
  }
  cout << flush;
}