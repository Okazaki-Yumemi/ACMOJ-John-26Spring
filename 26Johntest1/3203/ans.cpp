#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> nums;

    int x;
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>x;
        nums.push_back(x);    
    }


    //方法数的最多 n-k个
    //尝试翻转
    for(int i = 0; i <= n-k ; i++){
        vector<int> b = nums;
        reverse(b.begin()+ i, b.begin()+k+i);
        int cnt = 0;
        for(int j = 0; j < n ; j ++){
            int pi = b[j];
            int index = (pi + j)%n;
            if(b[index] >= pi ){
                cnt ++;
                if(cnt >= (n+1)/2 ){
                    ans++;
                    break;
                }
            }
        }
    }

    std::cout<<ans<<endl;
    return 0;

}