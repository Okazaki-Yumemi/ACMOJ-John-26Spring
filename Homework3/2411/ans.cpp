#include <bits/stdc++.h>
#include <math.h>

int main(){
    int64_t n;

    std::cin >> n;

    int64_t cnt = 0;
    
    for(int k = 0; (1LL << k) <= n ; k++){
        //统计第k位的贡献

        int64_t half = 1LL << k;
        int64_t period = half* 2;
        int64_t period_cnt = (n+ 1) / period;


        //完整周期贡献
        cnt += half * period_cnt;

        //不完整周期
        cnt += std::max<int64_t>(0, (n+1)%period - half);
    }

    std::cout<<cnt<<"\n";
    return 0;
}