#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <functional>

using namespace std;

int getOneCount(int prefix[], int start, int end){
	return prefix[end] - prefix[start - 1];
}
bool hasBeautifulSegments(int prefix[], pair<int, int> segments[], int segmentCount){
	for(int i = 0; i < segmentCount; i++){
		int ss = segments[i].first, se = segments[i].second, segmentLength = se-ss + 1, oneThreshold = floor(segmentLength / 2);
		bool isSegmentBeautiful = getOneCount(prefix, ss, se) > oneThreshold;
		if(isSegmentBeautiful) return true;
	}
	return false;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int m, segmentCount;
		cin >> m >> segmentCount;
		pair<int, int> segments[segmentCount];
		for(int i = 0; i < segmentCount; i++){
			cin >> segments[i].first >> segments[i].second;
		}
		int changeCount;
		cin >> changeCount;
		int changeIndexes[changeCount];
		for(int i = 0; i < changeCount; i++){
			cin >> changeIndexes[i];
		}

		int l = 1, r = changeCount + 1;
		while (l < r){
			int mid = floor((l + r)/2);

			//construct list
			set<int> changeSet;
			for(int i = 0; i < mid; i++) changeSet.insert(changeIndexes[i]);
			int prefix[m + 1];
			prefix[0] = 0;
			for(int i = 1; i <= m; i++){
				prefix[i] = prefix[i - 1];
				//i is in changeSet
				if(changeSet.find(i) != changeSet.end()) prefix[i] += 1;
			}
			bool midOK = hasBeautifulSegments(prefix, segments, segmentCount);
			if(midOK) r = mid;
			else l = mid + 1;
		}

		if(0 <= l && l <= changeCount) cout << l << endl;
		else cout << "-1" << endl;
	}
}