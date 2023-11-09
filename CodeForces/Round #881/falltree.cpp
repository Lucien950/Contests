#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;
typedef unsigned long long ull;

int dfs(int at, vector<int> adj[], ull outs[], set<int> * visited){
	vector<int> nextList = adj[at];
	int downstreamOuts = 0;
	for(int next: nextList) {
		if(visited->find(next) != visited->end()) continue;
		visited->insert(next);
		downstreamOuts += dfs(next, adj, outs, visited);
	}
	if(downstreamOuts == 0){
		outs[at] = 1;
		return 1;
	}
	outs[at] = downstreamOuts;
	return downstreamOuts;
}

int main(){
	int caseNum;
	cin >> caseNum;
	while (caseNum--){
		int n;
		cin >> n;
		vector<int> adj[n + 1];

		for(int i = 0; i < n-1; i++){
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ull outs[n+1];
		memset(outs, 0, sizeof(outs));
		set<int> visited = {1};
		dfs(1, adj, outs, &visited);


		int assumptionCount;
		cin >> assumptionCount;
		for(int i = 0; i < assumptionCount; i++){
			int sa, sb;
			cin >> sa >> sb;
			cout << outs[sa] * outs[sb] << endl;
		}
	}
}
