#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    for(int caseNum = 0; caseNum < cases; caseNum++){
        int l, r;

        // determine maxsize for a beautiful set
        // since max(r-l)=10**6-1, maxSize < log2(10**6-1) = 19.*
        int maxSize = 0;
        cin >> l >> r;
        int at = l;
        while(at <= r){
            at *= 2;
            maxSize += 1;
        }

        //determine the number of beautiful sets
//      DP approach (doesn't work fast enough)
        int dp[r-l+1][maxSize];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < r-l+1; i++) dp[i][0] = 1;
        for(int depth = 0; depth < maxSize - 1; depth++){
            for(int i = 0; i < r-l+1 ;i++){
                if (dp[i][depth] == 0) { continue; }
                int val = i + l;
                for(int m = 2; val * m <= r; m++){
                    dp[(val * m) - l][depth + 1] += dp[i][depth];
                }
            }
        }
        long long possibles = 0;
        for(int i = 0; i < r-l+1; i++){
            possibles = (possibles + dp[i][maxSize - 1]) % 998244353;
        }




        cout << maxSize << " " << possibles << endl;
    }
    return 0;
}