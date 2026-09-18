#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int n;
    cin>>n;

    unordered_map<char,char> map;

    for(int i = 0 ; i < n ; i++){
        char x, y;
        cin>>x>>y;

        map[x] = y;
    }

    string s;
    cin>>s;

    for(char c : s){
        if(map.count(c)){
            cout<<map[c];
        }else{
            cout<<c;
        }
    }
    cout<<endl;
    return 0;
}