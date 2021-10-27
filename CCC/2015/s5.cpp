#include <bits/stdc++.h>
using namespace std;


//variables
int originalPieCount, addPieCount;
//1 indexed lists waaaah
int originalPieList[3005], addPieList[105];

int dp[3005][2][105][105];


//solve(pos, 0, l, r)
//originalPieList[pos] + solve(pos+1, 0, l, r)
//addPieList[r]+solve(pos, 0, l, r-1)

//solve(pos+1, 1, l, r)
//solve(pos, 1, l+1, r)
int solve(int pos, int allowTake, int l, int r){
    //the laziest DP on the planet
    int& ret=dp[pos][allowTake][l][r];
    if(ret!=-1) return ret;

    if(pos==originalPieCount+1) {
		//out of bounds??
		//THIS CODE DOES NOT INCREMENT THE POSITION
        if(l<=r) {
            if(allowTake) return ret=addPieList[r]+solve(pos, 0, l, r-1);
            else return ret=solve(pos, 1, l+1, r);
        }
        else return ret=0;
    }

    if(allowTake) {
		//the max between not taking or taking the current position pie
        ret=max(solve(pos, 0, l, r), originalPieList[pos] + solve(pos+1, 0, l, r));

		//try taking the best one from M
        if(l<=r) ret=max(ret, addPieList[r]+solve(pos, 0, l, r-1));
    }
    else {
		//go to next one and be allowed to take
        ret=solve(pos+1, 1, l, r);

		//try ignoring the worst one
        if(l<=r) ret=max(ret, solve(pos, 1, l+1, r));
    }

    //if not allowTake and pos != originalPieCount+1
    return ret;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &originalPieCount);
    for(int i=1; i<=originalPieCount; i++)
        scanf("%d", originalPieList+i);
    scanf("%d", &addPieCount);
    for(int i=1; i<=addPieCount; i++)
        scanf("%d", addPieList+i);
    sort(addPieList+1, addPieList+1+addPieCount);

	//actual solving
    printf("%d\n", solve(1, 1, 1, addPieCount));
    return 0;
}
