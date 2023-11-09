#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll NMAX = 2e5 + 5, SQRMAX = 635;

int freq[SQRMAX][NMAX];
ll a[NMAX], b[NMAX];


//note: i < j in name schemes
void tc() {
	ll n, ans = 0;
	cin >> n;
	ll lim = sqrt(n * 2);

	//read a
	for (ll i = 0; i < n; i++) cin >> a[i];
	//read b, update freq
	for (ll i = 0; i < n; i++) {
		cin >> b[i];
		if (a[i] <= lim) freq[a[i]][b[i]]++;
	}


	//number of good pairs such that a1 = a2 and i != j
	for (ll i = 0; i < n; i++) { //O(n) through all of a and b
		if(a[i] <= lim) {
			int b2 = a[i] * a[i] - b[i]; //since ai * aj = b1 + b2 = X
			if (1 <= b2<= n)
				ans += freq[a[i]][b2];
		}
	}
	for (ll i = 2; i <= lim; i += 2)
		ans -= freq[i][i * i / 2]; //filter for i != j
	ans /= 2;


	for (ll i = 0; i < n; i++) { //O(n) through all of a and b
		int aj = a[i], b1 = b[i];
		for (ll ai = 1; (ai <= lim) && (ai < aj) && (ai * aj <= 2 * n); ai++) {
			ll b2 = ai * aj - b1;
			if (1 <= b2 <= n) ans += freq[ai][b2];
		}
	}

	//reset freq table
	for (ll i = 0; i < n; i++) { if (a[i] <= lim) freq[a[i]][b[i]] = 0; }
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll cases;
	cin >> cases;
	while (cases--) tc();
	return 0;
}