#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> color;
    unordered_map<string,int> size;
    unordered_map<string,int> age;

    // 初始化

    color["black"] = 1;
    color["white"] = 2;
    color["brown"] = 4;
    color["gray"] = 8;
    color["red"] = 16;
    color["rainbow"] = 1024;
    
    size["little"] = 64;
    size["middle"] = 512;
    size["large"] = 1024;

    age["baby"] = 32;
    age["teen"] = 1024;
    age["adult"] = 2048;
    age["aged"] = 8;

    string a, b,c;

    cin>>a>>b>>c;

    if(
        (color.find(a) == color.end()) ||
        (size.find(b) == size.end()) ||
        (age.find(c) == age.end())
    ){
        return 1;
    }
    else{
        cout<< 1LL* color[a] * size[b] * age[c]<<endl;
        return 0;
    }
}   