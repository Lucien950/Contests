// shit
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;

int noteCount, maxPitch, TA[1000001];
bool isS[1000001];
ll sampleCount, cur = 0;

int main(){
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> noteCount >> maxPitch >> sampleCount;
    // 
    if(sampleCount < 1LL*noteCount) {
        cout << "-1" << "\n";
        return 0;
    } //3 3 6
    for(int i = 1; i <= noteCount; i++){
        TA[i] = (TA[i-1]+1) % maxPitch;
        if(! TA[i]) TA[i] = maxPitch;
        if(i <= maxPitch) cur += 1LL*i;
        else cur += maxPitch;
    }
    if(sampleCount > cur) {
        cout << "-1" << "\n";
        return 0;
    }
    for(int i = noteCount; i >= 1; i--){
        if(cur == sampleCount) break;
        ll subtr = 1LL*maxPitch-1LL;
        if(i < maxPitch) subtr = 1LL*i-1LL;
        if(cur-subtr > sampleCount) {
            isS[i] = true;
            cur -= subtr;
        } else {
            ll dif = subtr-(cur-sampleCount);
            TA[i] = TA[i-dif-1];
            assert(TA[i] != 0);
            break;
        }
    }
    for(int i = 1; i <= noteCount; i++){
        if(isS[i]) TA[i] = TA[i-1];
        cout << TA[i];
        if(i != noteCount) cout << " ";
        else cout << "\n";
    }
}