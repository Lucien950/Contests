#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int fenceSections, artistCount;
    cin >> fenceSections >> artistCount;
    int artists[artistCount][3];
    for(int i = 0; i < artistCount; i++){
        cin >> artists[i][0] >> artists[i][1];
        artists[i][0] -= 1;
        artists[i][1] -= 1;
        artists[i][2] = artists[i][1] - artists[i][0] + 1;
    }
    qsort(artists, artistCount, sizeof(*artists),
            [](const void *arg1, const void *arg2)->int
            {
                int const *lhs = static_cast<int const*>(arg1);
                int const *rhs = static_cast<int const*>(arg2);
                return rhs[1] < lhs[1];
            });
    int dp[fenceSections];
    memset(dp, 0, sizeof dp);

    int atArtist = 0;
    for(int i = 1; i < fenceSections; i++){
        if(artists[atArtist][1] > i){
            dp[i] = dp[i-1];
            continue;
        }

        while(artists[atArtist][1] == i && atArtist < artistCount){
            int * atArtistObj = artists[atArtist];
            dp[i] = max(dp[i], max(dp[i-1], atArtistObj[2] + (atArtistObj[0] > 0 ? dp[atArtistObj[0]] : 0)));
            atArtist++;
        }
        if(atArtist >= artistCount){
            cout << fenceSections - dp[i] << endl;
            return 0;
        }
    }
    cout << fenceSections - dp[fenceSections - 1] << endl;
    return 0;
}