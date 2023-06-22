#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int brute(){
	//	v
	int v;
	cin >> v;

	// edges
	pair<int, int> edges[v-1];
	for(int i=0;i<v-1;i++) cin >> edges[i].first >> edges[i].second;

	//connectivity
	bool connected[v+1];
	memset(connected, false, sizeof(connected));
	connected[1] = true;
	for(int i = 0; i < v+1; i++) assert(connected[i] == false || i == 1);

	int rounds = 0, outNodes = v - 1;
	while(outNodes > 0){
		for(auto &&edge: edges){
			int a = edge.first, b = edge.second;
			if(connected[a] && !connected[b]) { //connectivity test
				connected[b] = true;
				outNodes -= 1;
			}
		}
		rounds++;
	}
	return rounds;
}

int dfs(int at, vector<pair<int, int>> adj[], bool visited[], int lastOrder = 0, int turns = 1){
	vector<pair<int, int>> nextNodes = adj[at];
	int maxTurn = turns;
	for(auto &&node: nextNodes){
		int nextNode = node.first, order = node.second;
		// prevent loopback
		if(visited[nextNode]) continue;
		visited[nextNode] = true;

		bool needNewTurn = lastOrder > order;
		maxTurn = max(maxTurn, dfs(nextNode, adj, visited, order, turns + needNewTurn));
	}
	return maxTurn;
}

int solve(){
	//	v
	int v;
	cin >> v;

	// edges
	vector<pair<int, int>> adj[v+1];
	for(int i=0;i<v-1;i++){
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}
	bool visited[v+1];
	memset(visited, false, sizeof (visited));
	visited[1] = true;
	return dfs(1, adj, visited);
}

int main(){
	int cases;
	cin >> cases;
	for(int caseNum = 0; caseNum < cases; caseNum++) cout << solve() << endl;
}