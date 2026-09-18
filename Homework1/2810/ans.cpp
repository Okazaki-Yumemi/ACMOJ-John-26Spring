#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n ;
    cin >>n;
    vector<long long> b(n-1);

    
    for(int i = 0 ; i < n-1 ; i++){
        cin>>b[i];
    }

    if(n == 2){
        //只有1个b，返回1~b-1
        cout<< b[0] -1 << endl;
        return 0;
    }

    //递推: a(i+1) = b(i) - a(i)
    // 遍历所有可能的 a0
    // a1 = b0 - a0
    // a2 = b1 - a1 = b1 - b0 + a0
    // a3 = b2 - a2 = b2 - b1 + b0 - a0
    // a4 = b3 - a3 = b3 - b2 + b1 - b0 + a0
    // ...

    //化简之后，就是： a0 < b0
    // a0 > b0 - b1
    // a0 < b2 - b1 + b0
    // a0 > b0 - b1 + b2 - b3


    //构建差:
    for(int i = 1 ; i < n-1 ; i++){
        b[i] -= b[i-1];
    }

    //现在b变成:
    //[b0, b1-b0, b2 -b1 + b0,...]
    //找偶数下表最小和奇数下标最大，取负数
    long long min_even = b[0], min_odd =  b[1];
    for(int i = 0; i < n-1; i+=2){
        min_even = min_even < b[i] ? min_even:b[i];
    }
    for(int i = 1 ; i < n - 1 ; i+=2){
        min_odd = min_odd < b[i]? min_odd:b[i];
    }

    long long R = min_even - 1;
    long long L = max(1LL, 1 - min_odd);

    cout << max(0LL, R - L + 1) << '\n';

    return 0;

}

