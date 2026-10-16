#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,k;

    cin>>N>>k;

    vector<int> a;
    vector<int> b;

    int x;
    for(int i= 0 ; i < N ; i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i = 0 ; i < N ; i++){
        cin>>x;
        b.push_back(x);
    }

    auto check = [&](int rate) -> bool {
        vector<int> c;
        for(int i = 0 ; i < N ; i++){
            c.push_back(200*b[i] - (2*rate - 1) * a[i]);
        }
        nth_element(c.begin(),c.begin()+k-1,c.end(),greater<int>());
        long long sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += c[i];
        }
        if(sum >= 0){
            return true;
        }else{
            return false;
        }
    };


    int left = -1;
    int right = 101;

    while(left  + 1< right){
        int mid = left + (right - left)/2;

        if(check(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout<<left<<endl;
    return 0;
}