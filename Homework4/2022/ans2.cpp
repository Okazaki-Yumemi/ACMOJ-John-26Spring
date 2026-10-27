#include <bits/stdc++.h>
using namespace std;

vector<long long>nums;
long long ans = 0;
void mergesort(int l , int r){
    if(l >= r){
        return;
    }
    int mid = l + (r - l )/2 ;
    mergesort(l, mid);
    mergesort(mid + 1, r);

    vector<long long> helper;

    int left = l;
    int right = mid+1;

    while(left <= mid && right <= r){
        if(nums[left] < nums[right]){
            //是一个顺序对,且下标也是满足的
            ans += (r-right + 1);
            helper.push_back(nums[left]);
            left ++;
        }else{
            helper.push_back(nums[right]);
            right ++;
        }
    }
    while (left <= mid){
        helper.push_back(nums[left]);
        left++;
    }
    while (right <= r){
        helper.push_back(nums[right]);
        right ++;
    }
    
    for(int i = 0 ; i < helper.size(); i++){
        nums[i+l] = helper[i];
    }
    return;
}

int main(){
    int n;
    cin >> n;
    nums.resize(n);
    long long x;
    for(int i = 0; i < n ; i ++){
        cin >> x;
        nums[i] = x -1LL*(i+1)*(i+1); 
    }
    mergesort(0,n-1);

    std::cout<<ans<<endl;
    return 0;
}