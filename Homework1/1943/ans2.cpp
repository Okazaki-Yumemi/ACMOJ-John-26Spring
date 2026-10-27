#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    stack<int> stk;

    while(cin >> n){
        stk.push(n);
    }

    while (!stk.empty())
    {
        cout<<stk.top()<<endl;
        stk.pop();
    }

    return 0 ;
    
}