#include <bits/stdc++.h>
using namespace std;

vector<long long> nums;

long long ans = 0;

void mergesort(int l,int r){
    if(l >= r){
        return;
    }
    int mid = l + (r - l)/2;

    mergesort(l,mid);
    mergesort(mid + 1,r);

    vector<long long>tmp;

    int left = l;
    int right = mid + 1;

    while(left <= mid && right <= r){
        if(nums[left] < nums[right]){
            ans += (r - right + 1) ;
            tmp.push_back(nums[left]);
            left++;
        }else{
            tmp.push_back(nums[right]);
            right++;
        }
    }
    //left 先到
    if(left > mid){
        for(;right <= r; right ++){
            tmp.push_back(nums[right]);
        }
    }
    if(right > r){
        for(; left <= mid; left ++){
            tmp.push_back(nums[left]);
        }
    }
    //拷贝
    for(int i = 0 ; i < tmp.size() ;i++){
        nums[l + i] = tmp[i];
    }
    return ;
}

int main(){
    int n;
    cin >> n;
    long long x;

    for(long long i = 0 ; i < n; i++){
        cin >> x;
        nums.push_back(x- (i+1) * (i+1));
    }
    //开始归并排序
    mergesort(0,n-1);
    std::cout<<ans<<endl;
    return 0;
}

