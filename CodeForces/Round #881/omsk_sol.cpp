#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct question { int u, v, x; };

struct info {
	int sum, minPrefL, maxPrefL, minPrefR, maxPrefR, minSeg, maxSeg;

	info(int el = 0) {
		sum = el;
		minSeg = minPrefL = minPrefR = min(el, 0);
		maxSeg = maxPrefL = maxPrefR = max(el, 0);
	}
};

info merge(info& a, info& b) {
	info res;
	res.sum = a.sum + b.sum;
	res.minPrefL = min(a.minPrefL, a.sum + b.minPrefL);
	res.maxPrefL = max(a.maxPrefL, a.sum + b.maxPrefL);
	res.minPrefR = min(a.minPrefR + b.sum, b.minPrefR);
	res.maxPrefR = max(a.maxPrefR + b.sum, b.maxPrefR);
	res.minSeg = min({a.minSeg, b.minSeg, a.minPrefR + b.minPrefL});
	res.maxSeg = max({a.maxSeg, b.maxSeg, a.maxPrefR + b.maxPrefL});
	return res;
}

const int MAXN = 200100;
const int lg = 17;

int up[MAXN][lg + 1];
info ans[MAXN][lg + 1];
int d[MAXN];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i <= lg; i++) up[i][0] = 0;
	ans[0][0] = info(1);
	d[0] = 0;

	int cur = 0;
	for (int q = 0; q < n; q++) {
		char c;
		cin >> c;
		if (c == '+') {
			int v, x;
			cin >> v >> x;
			v--;
			cur++;

			d[cur] = d[v] + 1;

			up[cur][0] = v;
			for (int j = 1; j <= lg; j++) up[cur][j] = up[up[cur][j - 1]][j - 1];

			// ans 2^(n-1) up
			ans[cur][0] = info(x);
			for (int j = 1; j <= lg; j++){
				auto twonminus1 = up[cur][j - 1];
				ans[cur][j] = merge(ans[cur][j - 1], ans[twonminus1][j - 1]);
			}
		} else {
			int u, v, x;
			cin >> u >> v >> x;
			u--; v--;

			if (d[u] < d[v]) swap(u, v);

			// move u and v to same level
			int dif = d[u] - d[v];
			info a, b;
			for (int i = lg; i >= 0; i--) {
				if ((dif >> i) & 1) {
					a = merge(a, ans[i][u]);
					u = up[i][u];
				}
			}


			if (u == v)  a = merge(a, ans[0][u]);
			else {
				for (int i = lg; (up[i][u] != up[i][v]) && (i >= 0); i--) {
					a = merge(a, ans[i][u]);
					u = up[i][u];
					b = merge(b, ans[i][v]);
					v = up[i][v];
				}

				a = merge(a, ans[1][u]);
				b = merge(b, ans[0][v]);
			}

			swap(b.minPrefL, b.minPrefR);
			swap(b.maxPrefL, b.maxPrefR);

			info res = merge(a, b);
			bool pass = res.minSeg <= x && x <= res.maxSeg;
			if (pass) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) solve();
}