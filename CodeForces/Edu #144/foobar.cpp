#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string REPEATING = "BFBFFBFF";
bool solve(int slen, string str){
    vector<int> validPointers {-1, 0, 1, 2, 3, 4, 5, 6, 7};
    for(int i = 0; i < slen; i++){
        vector<int> newValidPointers;
        for(int pointer: validPointers){
            int newPointer = (pointer+1) % 8;
            if(str[i]==REPEATING[newPointer]){
                newValidPointers.push_back(newPointer);
            }
        }
        if(newValidPointers.empty()) return false;
        validPointers = newValidPointers;
    }
    return true;
}

int main(){
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        int strLen;
        string fbstr;
        cin >> strLen >> fbstr;
        bool isValid = solve(strLen, fbstr);
        if(isValid){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }

//    string outstr;
//    for(int i = 0; i < 200; i++){
//        string toAdd;
//        if(i % 3 == 0) toAdd += 'F';
//        if(i % 5 == 0) toAdd += 'B';
//        outstr += toAdd;
//    }

//    cout << outstr;


    return 0;
}