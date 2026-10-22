#include"test.hpp" 
#include<vector>
#include<iostream>

bool compare(int l , int r);
void mergesort(int l, int r);
std::vector<int> pos;


std::vector<int> ans(int n)
{
    pos.resize(n);
    for(int i = 0 ; i < n ; i++){
        pos[i] = i+ 1;
    }
    std::vector<int> your_ans(n);
    
    mergesort(0,n-1);

    for(int i = 0 ; i < n ; i++){
        your_ans[pos[i] - 1] = i + 1;
    }


    return your_ans;
}

// query 返回 pl < pr且 l < r
//所以compare返回 pl > pr
bool compare(int l , int r){
    int x1 = query(l,r);
    int x2 = query(l+1,r);
    int x3 = query(l,r-1);
    int x4 = query(l+1,r-1);

    //p[l] > p[r] =
    int result = x1 ^ x2;
    result ^= x3;
    result ^= x4;

    return result == 1;
}

void mergesort(int l , int r){
    if(l >= r){
        return;
    }

    int mid = l + (r - l)/2;

    mergesort(l,mid);
    mergesort(mid + 1,r);

    std::vector<int> tmp;

    int left = l;
    int right = mid + 1;
    while(left <= mid && right <= r){
        if(!compare(pos[left],pos[right])){
            tmp.push_back(pos[left]);
            left ++;
        }else{
            tmp.push_back(pos[right]);
            right ++;
        }
    }
    if(left > mid){
        for(;right <= r; right++){
            tmp.push_back(pos[right]);
        }
    }
    if(right > r){
        for(; left <= mid; left++){
            tmp.push_back(pos[left]);
        }
    }

    for(int i = 0 ; i <= (r-l) ; i++){
        pos[l+i] = tmp[i]; 
    }
}