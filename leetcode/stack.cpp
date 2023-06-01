#include "stack"
#include "queue"
#include "iostream"

using namespace std;
int main(){
stack<int> s;
s.push(10);
s.push(12);
int a = s.top(); // a = 12
s.pop();


queue<int> q;
q.push(10);
q.push(12);
int b = s.top(); // b = 10
q.pop();
}