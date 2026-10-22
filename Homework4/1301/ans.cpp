#include<bits/stdc++.h>

using namespace std;

vector<int>nums;

unordered_map<int,int>cnt;

void mergesort(int l , int r){
    if(l >= r){
        return;
    }
    int mid = l + (r - l) / 2;


    mergesort(l,mid);
    mergesort(mid + 1, r);

    vector<int> tmp;

    int left = l;
    int right = mid + 1;

    while(left <= mid && right <= r){
        if(nums[left] < nums[right]){
            cnt[nums[left]] += right - mid - 1;
            tmp.push_back(nums[left]);
            left++;
        }else{
            //对于下标更大，然后数字却比你小的，到你左侧肯定和你发生交换
            cnt[nums[right]] += (mid - left + 1) ;
            tmp.push_back(nums[right]);
            right ++;
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
            cnt[nums[left]] += r-mid;
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
    int x;
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        nums.push_back(x);
    }

    mergesort(0, n-1);

    for(int i = 0 ; i < n ; i++){
        std::cout<<cnt[i+1]<<" ";
    }
    std::cout<<"\n";
    return 0;
}