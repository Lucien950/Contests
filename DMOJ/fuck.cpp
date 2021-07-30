#include <iostream>
using namespace std;
const long long MOD = 1000000007;
long long factorialList[1000001]= {1, 1};

long long power(long long num, long long pow, long long mod){
    long long test;
    for(test = 1; pow; pow >>= 1){
        if (pow & 1) test = (test * num) % mod;
        num = (num * num) % mod;
    }
    return test;
}

long long multiply(long long a, long long b){
    if(a == 0) return 0;
	return (factorialList[b] * power(factorialList[a-1], MOD-2, MOD))% MOD;
}

int main(){
	int taskCount;
	cin >> taskCount;
    for(int i = 2; i <= 1000000; i++){
        long long newAdd = factorialList[i-1] * i;
        factorialList[i] = newAdd % MOD;
    }

    for(int i = 0; i < taskCount; i++){
        int a, b;
        cin >> a >> b;
        cout << multiply(a, b) << endl;
    }
	return 0;
}