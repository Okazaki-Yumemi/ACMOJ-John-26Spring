#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , m ,k;
    cin >> n >> m >> k;

    vector<long long > a;
    vector<long long> b;

    long long x;
    for(int i = 0; i < n ; i ++){
        cin >>x;
        a.push_back(x);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> x;
        b.push_back(x);
    }


    // 二分答案，猜测第k小的营养值是 x = 6,只需要统计小于 6的格子数目

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // 要写两个数

    auto check = [&] (long long x) -> bool {
        auto num = [&] (long long target,int i) ->long long {
            //输入 x- a,返回b里面小于等于 x-a的元素数目;
            long long left = -1;
            long long right = b.size();

            while(left + 1 < right){
                long long mid = left + (right - left)/2;

                if(b[mid] <= x- a[i]){
                    left = mid;
                }else{
                    right = mid;
                }
            }
            //最后left + 1即为满足的个数
            return left + 1;

        };    
        //判断x是不是行的;
        long long sum = 0 ;
        for(int i = 0; i < n ; i++){
            sum += num(x, i);
        }
        // 现在就看sum是啥情况了，如果 sum < k，我们要找让 sum = k的
        return sum >= k;
    };


    long long left = a.front() + b.front() - 1;
    long long right = a.back() + b.back() ;

    while(left + 1 < right){
        long long mid = left + (right - left)/2;

        if(check(mid)){
            //mid这个值对应的小于它的数大于 k了
            //证明mid太大了
            right = mid;
        }else{
            left = mid;
        }
    }

    cout<<right<<endl;
    return 0;
}