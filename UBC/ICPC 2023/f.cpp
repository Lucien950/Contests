#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

#define MIN3(a, b, c) min(a, min(b, c))

int main() {
  int itemCount, itemsPerPage, initialPage, preselectCount, desiredCount;
  cin >> itemCount >> itemsPerPage >> initialPage >> preselectCount >> desiredCount;
  const int pageCount = (itemCount + itemsPerPage - 1) / itemsPerPage;

  bool isPreselected[pageCount][itemsPerPage];
  memset(isPreselected, 0, sizeof(isPreselected));
  for (int i = 0; i < preselectCount; i++) {
	int a;
	cin >> a;
	a--;
	isPreselected[a / itemsPerPage][a % itemsPerPage] = true;
  }
  bool isDesired[pageCount][itemsPerPage];
  memset(isDesired, 0, sizeof(isDesired));
  for (int i = 0; i < desiredCount; i++) {
	int a;
	cin >> a;
	a--;
	isDesired[a / itemsPerPage][a % itemsPerPage] = true;
  }

  int selectionCost = 0;
  int firstNonZeroPage = INT_MAX, lastNonZeroPage = INT_MIN;
  for (int pageIndex = 0; pageIndex < pageCount; pageIndex++) {
	int pageDesiredItemCount = 0;
	for (int i = 0; i < itemsPerPage; i++)
	  pageDesiredItemCount += isDesired[pageIndex][i];
	const int itemsOnPage = min(itemsPerPage, itemCount - pageIndex * itemsPerPage);
	int selectAllDeselectStrat = itemsOnPage - pageDesiredItemCount + 1;
	int deselectAllSelectStrat = pageDesiredItemCount + 1;
	int diffStrat = 0;
	for (int i = 0; i < itemsPerPage; i++)
	  diffStrat += isDesired[pageIndex][i] != isPreselected[pageIndex][i];
	const int pageCost = MIN3(selectAllDeselectStrat, deselectAllSelectStrat, diffStrat);
	if (pageCost > 0) {
	  const int page = pageIndex + 1;
	  firstNonZeroPage = min(firstNonZeroPage, page);
	  lastNonZeroPage = max(lastNonZeroPage, page);
	}
	selectionCost += pageCost;
  }

  if (selectionCost == 0) {
	cout << 0 << endl;
	return EXIT_SUCCESS;
  }

  const int leftNavDistance = max(0, initialPage - firstNonZeroPage),
            rightNavDistance = max(0, lastNonZeroPage - initialPage);
  const int navigationCost = 2 * min(leftNavDistance, rightNavDistance) + max(leftNavDistance, rightNavDistance);
  cout << selectionCost + navigationCost << endl;
}