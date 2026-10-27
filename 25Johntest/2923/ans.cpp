#include <bits/stdc++.h>
using namespace std;

static int best;
static int n ;
vector<int> minV(n+1);
vector<int> minS(n+1);

void dfs(int layersleft,
        int maxR,
        int maxH,
        int remainV,
        int usedS);

int main(){
    int v;
    cin >> v;
    cin >> n;

    best = INT_MAX;

    int maxR = sqrt(v) + 1;
    int maxH = v;
    minV.resize(n + 1);
    minS.resize(n + 1);

    minV[0] = 0;

    for(int i = 1; i <= n; i++){
        minV[i] = minV[i-1] + 1LL*i*i*i;
    }

    minS[0] = 0;
    for(int i = 0 ; i <= n ; i++){
        minS[i] = i*(i+1)*(2*i+1)/3;
    }
    
    dfs(n,maxR,maxH,v,0);
    best = (best==INT_MAX)?0:best;
    std::cout<<best<<"\n";
    return 0;
}

void dfs(int layersleft,
        int maxR,
        int maxH,
        int remainV,
        int usedS){
            if(layersleft == 0){
                if(remainV == 0){
                    best = min(best,usedS);
                }
                return ;
            }
            // maxR是3，还需要4层，肯定不，H同理
            if(maxR < layersleft || maxH < layersleft){
                return;
            }
            // remainV 小于当前层的最小值，不用算了
            if(remainV < minV[layersleft]){
                return;
            }
            // 用了的和最小的大于best，不用算了
            if(usedS + minS[layersleft] >= best){
                return ;
            }

            // 剩余侧面积下界
            if(usedS + (2LL* remainV + maxR - 1) / maxR >= best){
                return;
            }

            int m = layersleft ;
            int available = remainV - minV[m - 1];
            int rMax = std::min(maxR, (int)sqrt((double)available / layersleft));

            for(int r = rMax ; r >= m ; r--){
                int base = (m == n) ? r*r : 0;

                //剩余体积确定高度
                int hMax = min(maxH , available / (r * r));

                // 根据最优解限制高度
                long long budget = 1LL * best - 1 - usedS - base - minS[m-1];

                if(budget < 2LL* r * m){
                    continue;
                }

                hMax = std::min(hMax , (int)(budget / (2LL * r)));

                if(hMax < m){
                    continue;
                }

                if(m == 1){
                    //最后一层的高度是被体积唯一确定的
                    if(remainV %(r*r) == 0){
                        int h = remainV / (r*r);

                        if(h >= 1 && h <= hMax){
                            best = min(best , usedS + base + 2*r*h);
                        }
                    }
                    continue;
                }

                // 其他层，dfs
                for(int h = hMax ; h >= m ; h--){
                    int V = r * r * h;
                    int new_usedS = usedS + base + 2* r* h;
                    if(new_usedS + minS[m - 1] >= best){
                        continue;
                    }

                    dfs(m-1,
                        r-1,
                        h-1,
                        remainV - V,
                        new_usedS);
                }
            }
        }