#include <bits/stdc++.h>
#include <ranges>
using namespace std;


int main(){

    long long m,n;
    cin>>n>>m;

    vector<int> nums;

    for(int i = 0; i < n ; i++){
        int x ; 
        cin>>x;
        nums.push_back(x);
    }


    auto check = [&](long long limit) -> bool {
        long long sum = 0;
        int part = 1;
        for(int i = 0; i< nums.size() ; i++){
            sum += nums[i];
            if(sum > limit){
                sum = nums[i];
                part++;
            }
        }
        return part <= m;
    };

    long long left = *max_element(nums.begin(), nums.end()) - 1;;
    long long right = accumulate(nums.begin(), nums.end(), 0LL);

    while(left + 1 < right){
        long long mid = left + (right - left) / 2;
        (check(mid)? right : left) = mid;
    }

    cout<<right<<'\n'; //最小的true
    return 0;
}