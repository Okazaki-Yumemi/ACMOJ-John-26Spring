#include <bits/stdc++.h>
using namespace std;

int main(){
    // 设位于第i行第j列
    // 对角线编号为 i + j - 1
    // 到k条对角线，一共有:
    int n;
    cin >> n;
    long long k =  ceil((sqrt(8LL*n+ 1) - 1)/ 2) ;

    // 当前对角线第几个:
    long long p = n - k*(k-1)/2 ;

    // so
    long long j = p;
    long long i = k + 1 - p;

    if(k % 2){
        cout<<i<<"/"<<j<<endl;
    }else{
        cout<<j<<"/"<<i<<endl;
    }
    
    return 0;

}