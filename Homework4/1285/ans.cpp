#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int remaining;

void construct(int l , int r){
    //不需要了
    if(remaining == 0 || r - l <= 1){
        return;
    }

    int mid = l + (r - l)/2;

    //修改当前区间
    swap(a[mid - 1], a[mid]);

    remaining --;

    construct(l,mid);
    construct(mid,r);
}

int main(){
    int n , k;
    cin >> n >> k;

    if(k % 2 == 0 || k < 1 || k > 2* n - 1){
        std::cout << "-1"<<endl;
        return 0;
    }

    remaining = (k - 1)/ 2;

    for(int i = 0 ; i < n ; i++){
        a.push_back(i+1);
    }

    // 交换swap(n - 1次,也就是 k-1/2)
    
    construct(0,n);
    
    for(int i = 0 ; i < n ; i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<endl;

    return 0;
}