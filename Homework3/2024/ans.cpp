#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,s;

    cin>>n>>s;

    vector<long long> t;
    vector<long long> a;
    long long x;
    long long non_zero_cnt = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>x;
        t.push_back(x);
        cin>>x;
        if(x) non_zero_cnt ++;
        a.push_back(x);
    }

    auto check = [&](long long limit) -> bool {
        //开始查询
        long long max_mem = 0;
        long long mem_used = 0;
        for(int i = 0 ; i < n ; i++){
            long long mem_curr = a[i] * max(0LL, limit - t[i]);
            max_mem = max_mem > mem_curr ? max_mem : mem_curr;
            mem_used += mem_curr;
        }

        if(mem_used - max_mem <= s){
            return true;
        }
        return false;
    };

    //先检查ai;
    if(non_zero_cnt <= 1){
        cout<<-1<<endl;
        return 0;
    }

    long long left = 0;
    long long right = *max_element(t.begin(), t.end()) + s + 1;


    while(left + 1 < right){
        long long mid  = left + (right - left)/ 2;

        if(check(mid)){
            //找最大值
            left = mid;
        }else{
            right = mid;
        }
    }

    cout<<left + 1 <<endl;

    return 0;
}