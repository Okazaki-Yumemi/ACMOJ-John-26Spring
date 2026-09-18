#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> stk;


    int n;
    while(cin>>n){
        stk.push(n);
    }

    while (!stk.empty())
    {
        cout<<stk.top()<<endl;
        stk.pop();
    }
    return 0;
}