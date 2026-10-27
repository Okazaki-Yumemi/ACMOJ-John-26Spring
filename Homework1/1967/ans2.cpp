#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n;
    unordered_map<char,char> m;

    char x,y;
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        m[x] = y;
    }

    string s;
    cin >> s;
    for(char ch : s){
        if(m.count(ch)){
            std::cout<<m[ch];
        }else{
            std::cout<<ch;
        }
    }

    cout<<"\n";
    return 0;

}