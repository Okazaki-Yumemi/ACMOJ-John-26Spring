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


    long long sum_rain = 0;
    vector<long long> human_capacity(n+1);
    for(long long i = 0 ; i < n ; i++){
        cin >> x;
        human_capacity[i] = x;
        sum_rain += x;
    }

    //那这不就是前缀和？
    //先暴力做吧。

    vector<long long> cnt(n);

    // i 气球编号 （0-based)
    // k 伦次
    

    // 没通过的测试点都来自  大m，因此肯定不能绕着那个啥展开了。
    // 然后注意到呢，一个雨云会反反复复遇见很多次同一个气球。
    // 从而有可能直接 用求和的方式得到其会在哪一个地方耗尽，最后在单独分析。

    // 先对气球能力求和
    // 我们放在了sum_rain里面。
    vector<long long> rows;
    // 后面发现，每一个row我们都遍历一次，重复了，直接求和
    long long sum_rows = 0;
    for(long long i = 0; i < n ; i++){
        long long row = rain_capacity[i]/sum_rain;
        //一轮需要n次 ，实验模拟 m次，最大轮数 m/n
        row = min(row , m/n);
        rows.push_back(row);
        sum_rows += row;
        rain_capacity[i] -= row * sum_rain;
    }

    for(long long i = 0; i < n; i++){
        cnt[i] += sum_rows * human_capacity[i];
    }

    //现在这个地方就让我们知道每个雨云能够抗住几次循环的sum了
    // 我们再从每个 雨云的 地址开始，往前面循环走。如果归0就break
    // 先来看一个雨云让cnt得吃多少.
    // 这个循环可以和上面合并在一起，我直接写上面了。
    // 一个row里面的数字能让所有的气球都爽这么多次。
    
    //现在的这个雨云就是空的了。
    //我们从它的指针往前走
    // 刚刚是70分，现在得想办法让这个地方能够往前走了
    // 现在我们的算法还在依靠每个雨云往前面遍历。
    // 改为前缀和。


    // 把气球能力数组倒过来，再复制
    // 我们已经知道最后一次访问顶多为n，那么雨云遇到起球的顺序就是这个数组的向右连续区间
    // 雨云i对应的连续的起点就是 n - 1 - i;
    vector<long long> B(2*n);
    for(int j = 0; j < 2*n; j++){
        B[j] = human_capacity[n-1-(j%n)];
    }

    vector<long long> pre(2*n+1, 0);

    for(int j = 0 ; j < 2*n ; j++){
        pre[j+1] = pre[j] + B[j];
    }

    vector<long long> diff(2* n);
    // 现在一个雨云，从start开始，让t个气球降雨，就是要消耗
    // pre[start + t] - pre[start]。 
    // 开始查看这个雨云的含量。

    for(long long i = 0; i < n; i++){
        long long start = n - i - 1;
        
        auto check = [&] (long long t) -> bool {
            if(pre[start+t] - pre[start] <= rain_capacity[i]){
                //放得下
                return true;
            }else{
                return false;
            }
        };
        //最大伦次
        long long limit = min(n, m - rows[i] * n);
        long long l = -1;
        long long r = limit + 1;

        while(l+1 < r){
            long long mid = l + (r - l)/2;
            if(check(mid)){
                //mid太辣，放的下
                l = mid;
            }else{
                r = mid;
            }
        }

        long long t = l;

        diff[start] ++;
        diff[start+t] --;

        //然后用cnt加上剩余的
        long long remain = rain_capacity[i] - (pre[start+t] - pre[start]);

        if(t < limit && remain > 0){
            cnt[(i - t + n) % n] += remain;
        }
    }

    //现在处理差分数组。
    // 里面记录的是贡献次数
    for(long long i = 1; i < 2*n ; i++){
        diff[i] += diff[i - 1];
    }

    // B是倒叙的，我们从这个地方还原
    for(long long i = 0; i < n; i++){
        // 原气球 i 对应的 B 下标 是 n - 1 - i;
        long long q = n - 1 - i;

        cnt[i] += (diff[q] + diff[q+n]) * human_capacity[i];
    }




    for(long long i = 0 ; i < n ; i++){
        std::cout<<cnt[i]<<" ";
    }
    std::cout<<endl;

}