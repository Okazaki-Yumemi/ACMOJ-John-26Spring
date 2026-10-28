// 五条悟老师你带我走吧 /(ㄒoㄒ)/~~
// 五条悟必秒宿傩
// 秒毛
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long  n,m;
    cin >> n >> m;

    vector<long long> rain_capacity(n);
    long long x;
    for(int i = 0;  i < n ; i++){
        cin >> x;
        rain_capacity[i] = x;
    }

    vector<long long> human_capacity(n+1);
    for(long long i = 0 ; i < n ; i++){
        cin >> x;
        human_capacity[i] = x;
    }

    //那这不就是前缀和？
    //先暴力做吧。

    vector<long long> cnt(n);

    // i 气球编号 （0-based)
    // k 伦次
    for(long long k = 1; k <= m ; k++){
        for(long long i = 0; i < n ; i++){
            long long pos = (i + k - 1) % n;

            long long rain = min(rain_capacity[pos],human_capacity[i]);

            rain_capacity[pos] -= rain;
            cnt[i] += rain;
        }
    }

    for(long long i = 0 ; i < n ; i++){
        std::cout<<cnt[i]<<" ";
    }
    std::cout<<endl;

}