#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	q.push(a);
  }

  while (q.size() > k) {
	int a[k];
	for (int i = 0; i < k; i++) {
	  a[i] = q.top();
	  q.pop();
	}
	for (int i = 0; i < k - 1; i++) {
	  a[i] -= a[k - 1];
	  if (a[i] != 0) {
		q.push(a[i]);
	  }
	}
  }

  int residuals = q.top() * k;
  while (!q.empty()) {
	residuals -= q.top();
	q.pop();
  }

  cout << residuals << endl;
}