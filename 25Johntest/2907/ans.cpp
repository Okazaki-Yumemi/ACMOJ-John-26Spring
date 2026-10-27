#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;

    vector<long long> nums(n);

    int x;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        nums[i] = x;
        sum += x;
    }

    // 二分答案
    auto check = [&](long long max) -> bool {
        // 用贪心，看看划分这个段的数目能不能成功进入。
        long long curr_sum = 0 ;
        long long cnt = 1;
        for(int i = 0 ; i <  n ; i++){
            if(nums[i] > max){
                return false;
            }
            if(curr_sum + nums[i] > max){
                //这一段超出了
                //开新的一段
                cnt ++;
                curr_sum = nums[i];
            }else{
                //没超出
                curr_sum += nums[i];
            }
        }

        return cnt <= m;
    };


    //开始尝试
    long long l = -1;
    long long r = sum + 1;
    
    while(l + 1 < r){
        long long mid = l + (r - l)/2;
        if(check(mid)){
            //check 为真，代表 cnt小，证明mid太大
            r = mid;
        }else{
            l = mid;
        }
    }
    std::cout<<r<<endl;
    return 0;

}