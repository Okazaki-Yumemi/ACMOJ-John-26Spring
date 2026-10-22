#include <bits/stdc++.h>
using namespace std;

int main(){

    int n ;
    cin >>n;

    string s = "";
    string max = "";
    int cnt = 1;
    cin >> max;

    for(int i = 0 ; i < n - 1; i ++){
        cin >> s;

        if(max.length() > s.length()){
            continue;
        }else if (max.length() < s.length()){
            max = s;
            cnt = i + 2;
        }else{
            if(s > max){
                max = s;
                cnt = i + 2;
            }
        }
    }
    std::cout<<cnt<<endl;
    std::cout<<max<<endl;


    return 0;
}