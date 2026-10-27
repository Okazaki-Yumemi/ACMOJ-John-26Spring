#include<bits/stdc++.h>

using namespace std;

vector<int>nums;

unordered_map<int,int>cnt;

void mergesort(int l , int r){
    if(l >= r){
        return;
    }
    int mid = l + (r - l)/2;

    mergesort(l,mid);
    mergesort(mid + 1,r);

    vector<int> helper;
    int left = l;
    int right = mid + 1;

    while(left <= mid && right <= r){
        if(nums[left] < nums[right]){
            cnt[nums[left]] += (right - mid - 1);
            helper.push_back(nums[left]);
            left ++;
        }else{
            cnt[nums[right]] += (mid - left + 1);
            helper.push_back(nums[right]);
            right ++;
        }
    }

    while(left <= mid){
        cnt[nums[left]] += (r - mid);
        helper.push_back(nums[left]);
        left ++;
    }
    while(right <= r){
        helper.push_back(nums[right]);
        right ++;
    }

    for(int i = 0 ; i < helper.size() ; i++){
        nums[i+l] = helper[i];
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