#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;
	while (cases--){
		int n;
		cin >> n;
		int nums[n];

		ll sum = 0, moves = 0;
		for(int i = 0; i < n; i++){
			cin >> nums[i];
			sum += abs(nums[i]);
		}

		bool isNegativeZone = false;
		for(int i = 0; i < n; i++) {
			if (nums[i] == 0) continue;
			bool numNegative = nums[i] < 0;
			if(!numNegative && isNegativeZone) moves++;
			isNegativeZone = numNegative;
		}
		if(isNegativeZone) moves += 1;

		cout << sum << " " << moves << endl;
	}
}