#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

//pair<int, int> getMinMaxBetween(int v1, int v2, const vector<vector<int>> * adj, const vector<int> * weights, int acc, pair<int, int> retVal, bool visited[]){
//	if(v1 == v2) return retVal;
//
//	pair<int, int> outRetVal = retVal;
//	for(auto next: (* adj)[v1]){
//		if(visited[next]) continue;
//		visited[next] = true;
//
//		int newAcc = acc + (* weights)[next];
//		pair<int, int> newRetVal = pair<int, int>(min(retVal.first, newAcc), max(retVal.second, newAcc));
//		pair<int, int> mm = getMinMaxBetween(next, v2, adj, weights, newAcc, newRetVal, visited);
//
//		outRetVal.first = min(outRetVal.first, mm.first);
//		outRetVal.second = max(outRetVal.second, mm.second);
//	}
//	return outRetVal;
//}
//pair<int, int> getMinMaxBetween(int v1, int v2, const vector<vector<int>> * adj, const vector<int> * weights){
//	int v1Weight = (* weights)[v1];
//	bool visited[adj->size()]; //perhaps make this a set?
//	memset(visited, false, sizeof(visited));
//	return getMinMaxBetween(v1, v2, adj, weights, v1Weight, pair<int, int>(v1Weight, v1Weight), visited);
//}

struct LCANode{
	int minVal, maxVal, sum;
	LCANode(int el = 0){
		sum = el;
		minVal = min(0, el);
		maxVal = max(0, el);
	}
};

const int MAXNODES = 2e5 + 1;
const int lg = 19;
int up[MAXNODES][lg];
LCANode LCAs[MAXNODES][lg];
int depths[MAXNODES] = {0};

LCANode merge(LCANode * n1, LCANode * n2){
	LCANode r;
	r.sum = n1->sum + n2->sum;
	r.minVal = min(n1->minVal, n2->minVal);
	r.maxVal = max(n1->maxVal, n2->maxVal);
	return r;
}

bool query(int v1, int v2, int cost){
	//choose empty path
	if (cost == 0) return true;

	// make v1 the shallower node
	if(depths[v1] > depths[v2]) swap(v1, v2); //depths[v1] <= depths[v2]

	int diff = depths[v2] - depths[v1]; // >= 0
	LCANode v1LCA, v2LCA;
	for(int i = 0; (i < lg); i++){
		if((diff >> i) & 1){
			v2LCA = merge(&v2LCA, &LCAs[v2][i]);
			v2 = up[v2][i];
		}
	}
}

int main(){
	int cases;
	cin >> cases;
	for(int caseNum = 0; caseNum < cases; caseNum++){
		int events;
		cin >> events;

		int curStation = 2;
		for(int eventNum = 0; eventNum < events; eventNum++){ //max iterations = 2e5
			char action;
			cin >> action;
			if(action == '+'){ //add item
				int targetV, weight; //constraint w == 1 || w == -1
				cin >> targetV >> weight;

				// populate depths
				depths[curStation] = depths[targetV] + 1;

				//binary lift arrays
				// populate up
				up[curStation][0] = targetV;
				for(int i = 1; i < lg; i++)
					up[curStation][i] = up[ up[curStation][i-1] ][i-1];

				//populate LCAs
				LCAs[curStation][0] = LCANode(0);
				for(int i = 1; i < lg; i++)
					LCAs[curStation][i] = merge(&LCAs[curStation][i-1], &LCAs[ up[curStation][i-1] ][i-1]);

				// push curstation
				curStation++;
			}
			else if(action == '?'){ //query
				int v1, v2, cost;
				cin >> v1 >> v2 >> cost;
				if(query(v1, v2, cost)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
}