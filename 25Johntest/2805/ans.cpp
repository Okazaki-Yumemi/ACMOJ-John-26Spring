#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k;
    cin >> n >> k;

    //滑动窗口。
    vector<int> two(n);
    vector<int> five(n);
    vector<int> nums(n);
    auto divide = [&] (int num, int divide) -> int {
        if(num == 0) return 0;
        int ans = 0;
        while(num % divide == 0){
            ans ++;
            num /= divide;
        }
        return ans;
    };

    int x;
    long long two_sum = 0;

    long long five_sum = 0;
    for(int i = 0 ; i < n;  i++){
        cin >> x;
        nums[i] = x; 
        two[i] = divide(x, 2);
        two_sum += two[i];
        five[i] = divide(x,5);
        five_sum += five[i];
    }
    //总的 0 的数目
    long long ten_sum = min(two_sum,five_sum);
    long long demand = ten_sum - k;
    if(demand < 0){
        cout << 0 << "\n";
        return 0;
    }

    //我们滑窗的区间删除的数目小于等于 demand个
    //滑动窗口
    int left = 0;
    int del_two_sum = 0;
    int del_five_sum = 0;
    int del_ten = 0 ;
    long long ans = 0;
    for(int right = 0 ; right < n ;right ++){
        //右指针进入
        del_two_sum += two[right];
        del_five_sum += five[right];
        del_ten = ten_sum - min(two_sum - del_two_sum, five_sum - del_five_sum);

        while(del_ten > demand){
            //左侧移动
            del_two_sum -= two[left];
            del_five_sum -= five[left];
            del_ten = ten_sum - min(two_sum - del_two_sum, five_sum - del_five_sum);
            left++;
            
        }
        ans += right - left + 1;
    }
    std::cout<<ans<<endl;
    return 0;
}