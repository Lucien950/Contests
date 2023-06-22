#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

int brute(int n, const int a[], const int b[]){
	int res = 0;
	for(int j = 0; j < n; j++){
		for(int i = 0; i < j; i++){
			if(a[i] * a[j] == b[i] + b[j]) res++;
		}
	}
	return res;
}

int solve(const int n, const int a[], const int b[]){
	int res = 0;

	pair<int, int> pos[n];
	for(int i = 0; i < n; i++){
		pos[i] = make_pair(a[i], b[i]);
	}
	sort(pos, pos+n);

	for(int a1Pos = 0; pow(pos[a1Pos].first, 2) <= 2 * n && a1Pos < n; a1Pos++){ // a1 = min(ai, aj) <= sqrt(2n)
		for(int a2Pos = a1Pos + 1; pos[a1Pos].first * pos[a2Pos].first <= 2 * n && a2Pos < n; a2Pos++){ //ai * aj = bi + bj <= 2n
			int a1 = pos[a1Pos].first, a2 = pos[a2Pos].first;

			if(a1Pos == a2Pos) continue;
			if(a1 == a2 && a1Pos > a2Pos) continue; //if we are pulling from the same positions, we do this to force uniqueness WLOG

			int targetBSum = a1 * a2;

			int b1 = pos[a1Pos].second, b2 = pos[a2Pos].second;
			if(b1 + b2 == targetBSum) res++;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int cases;
	cin >> cases;
	for(int caseNum = 0; caseNum < cases; caseNum++){
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];

		//cout << brute(n, a, b) << endl;
		cout << solve(n, a, b) << endl;
	}
}