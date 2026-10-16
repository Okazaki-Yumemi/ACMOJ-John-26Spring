#include <bits/stdc++.h>

using namespace std;

int main(){


    //题目要求最大值，就采用二分的方法。

    //怎么判断一个值合不合法？就看能否组合出这个最小值。

    long long n , m;
    cin>> n >> m;

    vector<long long> Ai;
    vector<long long> Bi;

    long long x;
    for(int i = 0; i < n ; i++){
        cin>>x;
        Ai.push_back(x);
    }

    for(int i = 0 ; i < n ; i++){
        cin >> x;
        Bi.push_back(x);
    }

    //Ai Bi装好了

    long long time = m * n;
    auto check = [&](long long limit) -> bool {
        //检查的时候怎么检查呢。用贪心？
        //对于每一门课程，看看其至少用几个课时就能做到学完。
        long long time_used = 0;

        for(int i = 0 ; i < n ; i++){
            //开始检查每一个课程
            if(Ai[i] > Bi[i]){
                //上课优先
                if(limit >= Ai[i] * m){
                    //所有课上课都不够
                    //需要自习来补,向上取整
                    time_used += m + (limit - Ai[i]*m + Bi[i] - 1)/Bi[i];
                }else{
                    time_used += (limit + Ai[i] - 1) / Ai[i];
                }
            }else{
                //自习优先
                time_used += (limit + Bi[i] - 1)/ Bi[i];
            }
            if(time_used > time) return false;
        }

        //都没炸
        return  true;
    };

    //开始二分,最小的可能值是0，最大的是
    long long left = 0;
    long long maxA = *max_element(Ai.begin(),Ai.end());
    long long maxB = *max_element(Bi.begin(),Bi.end());

    long long right = m * max(maxA , maxB) + 1;

    //寻找最大
    while(left + 1 < right){
        long long mid = left + (right - left)/2;

        if(check(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout<<left<<endl;
    return 0;
}