#include <iostream>
#include <string>
using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;

    for(int ai = 0; ai < a.length(); ai++){
        for(int bi = 0; bi < b.length(); bi++){
            bool frontLoad = ai == 0 && bi == 0;
            bool backLoad = ai == a.length() - 1 && bi == b.length() - 1;

            bool case1 = a[ai] == b[bi] && (frontLoad || backLoad);

            bool endInBounds = ai+1<a.length() && bi+1<b.length();
            bool case2 = endInBounds && a.substr(ai, 2) == b.substr(bi, 2);
            if(case1){
                cout << "YES" << endl;
                if(frontLoad) cout << a[ai] << "*" << endl;
                else if(backLoad) cout << "*" << a[ai] << endl;
                return;
            }
            if(case2){
                cout << "YES" << endl;
                if(ai == a.length() - 1 && bi == b.length() - 1){
                    cout << "*" << a.substr(ai, 2) << endl;
                }
                else{
                    cout << "*" << a.substr(ai, 2) << "*" << endl;
                }
                return;
            }
        }
    }
//    doesn't work
    cout << "NO" << endl;
}

int main(){
    int cases;
    cin >> cases;
    for(int caseNum = 0; caseNum < cases; caseNum++){
        solve();
    }
    return 0;
}