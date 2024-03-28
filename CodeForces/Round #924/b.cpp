#include <assert.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, leftToOutput;
	cin >> n >> leftToOutput;
	leftToOutput *= 2;
	int a[n];
	vector<int> aSingles, aDoubles;
	aSingles.reserve(n);
	aDoubles.reserve(n);
	int b[n];
	vector<int> bSingles, bDoubles;
	bSingles.reserve(n);
	bDoubles.reserve(n);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
	  int in;
	  cin >> in;
	  a[in - 1] += 1;
	}
	for (int i = 0; i < n; i++) {
	  if (a[i] == 1) {
		aSingles.push_back(i + 1);
	  } else if (a[i] == 2) {
		aDoubles.push_back(i + 1);
	  }
	}
	for (int i = 0; i < n; i++) {
	  int in;
	  cin >> in;
	  b[in - 1] += 1;
	}
	for (int i = 0; i < n; i++) {
	  if (b[i] == 1) {
		bSingles.push_back(i + 1);
	  } else if (b[i] == 2) {
		bDoubles.push_back(i + 1);
	  }
	}

	vector<int> aOut, bOut;
	aOut.reserve(leftToOutput);
	bOut.reserve(leftToOutput);
	// add pairs to both
	while (leftToOutput > 1 && !aDoubles.empty() && !bDoubles.empty()) {
	  aOut.push_back(aDoubles.back());
	  aOut.push_back(aDoubles.back());
	  bOut.push_back(bDoubles.back());
	  bOut.push_back(bDoubles.back());
	  aDoubles.pop_back();
	  bDoubles.pop_back();
	  leftToOutput -= 2;
	}
	// add singles to both
	while (leftToOutput > 0) {
	  if (aSingles.empty() || bSingles.empty()) {
		return EXIT_FAILURE;
	  }
	  aOut.push_back(aSingles.back());
	  bOut.push_back(bSingles.back());
	  aSingles.pop_back();
	  bSingles.pop_back();
	  leftToOutput -= 1;
	}

	// output aOut, then bOut
	for (const int i : aOut) {
	  cout << i << " ";
	}
	cout << endl;
	for (const int i : bOut) {
	  cout << i << " ";
	}
	cout << endl;
  }
}
