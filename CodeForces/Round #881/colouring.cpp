#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

int COLORS[50];

using namespace std;
int main(){
	int cases;
	cin >> cases;
	for(int caseNum = 0; caseNum < cases; caseNum++){
		int itemCount;
		cin >> itemCount;
		for(int i = 0; i < itemCount; i++) cin >> COLORS[i];

		sort(COLORS, COLORS + itemCount);
		int sum = 0;
		for(int i = 0; i < itemCount / 2; i++) sum += COLORS[(itemCount - 1) - i] - COLORS[i];
		cout << sum << endl;
		memset(COLORS, 0, sizeof(COLORS));
	}
}