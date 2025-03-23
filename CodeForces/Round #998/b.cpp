#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

constexpr size_t MAX_CARD_COUNT = 2000;
constexpr size_t MAX_COW_COUNT = 2000;
static array<array<int, MAX_CARD_COUNT>, MAX_COW_COUNT> cow_cards;
static array<int, MAX_COW_COUNT> order;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int cow_count, cards_per_cow;
	cin >> cow_count >> cards_per_cow;
	for (int cow = 0; cow < cow_count; cow++) {
	  for (int card = 0; card < cards_per_cow; card++) {
		cin >> cow_cards[cow][card];
	  }
	  std::sort(cow_cards[cow].begin(), cow_cards[cow].begin() + cards_per_cow);
	}
	// now we have a series of cow, with sorted cards

	for (int i = 0; i < cow_count; i++) {
	  order[i] = i;
	}
	std::sort(order.begin(), order.begin() + cow_count,
	          [](const int a, const int b) { return cow_cards[a][0] < cow_cards[b][0]; });

	// enforce the order
	int top_card = -1;
	for (int turn = 0; turn < cards_per_cow; turn++) {
	  for (int cow_i = 0; cow_i < cow_count; cow_i++) {
		const int cow_num = order[cow_i], cow_card = cow_cards[cow_num][turn];
		if (cow_card <= top_card)
		  goto fail;
		top_card = cow_card;
	  }
	}

	for (int i = 0; i < cow_count; i++) {
	  cout << order[i] + 1 << " ";
	}
	cout << endl;
	continue;
  fail:
	cout << -1 << endl;
  }
}