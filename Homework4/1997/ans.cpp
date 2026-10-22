#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,X,Y;
    cin >> n>>X>>Y;

    //只需要每次递归都让Pivot是当前区间的最小值就可以了。
    //从 [0，1，2，3，4，5..., n] 反着构造

    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        ans.push_back(i);
    }


    for(int l = n - 2 ; l >= 0 ; l --){
        int p = l +((n - 1 - l)* X)/Y;
        swap(ans[l],ans[p]);
    }

    for(int i = 0 ; i < n ; i++){
        std::cout<<ans[i]<<" ";  
    }
    std::cout<<endl;
    return 0;
}