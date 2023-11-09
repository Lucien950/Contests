#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string.h>

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
	int lim = ceil(sqrt(2 * n));
	int freq[lim][n];
	memset(freq, 0, sizeof(freq));
	for(int i = 0; i <= n; i++){
		if(a[i] <= lim){
			freq[a[i]][b[i]]++;
		}
	}
	// ai = aj
	for(int i = 0; i < n; i++){
		int a12 = a[i], b1 = b[i];
		if(a[i] <= lim){
			int b2 = a12 * a12 - b1;
			if (1 <= b2 <= n) res += freq[a12][b2];
		}
	}
	for(int i = 2; i < lim; i += 2)
		res -= freq[i][i * i / 2];
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