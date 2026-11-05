#include <bits/stdc++.h>
using namespace std;
const long long  MOD = 1000000007;
int main(){
    std::ios::sync_with_stdio(0);

    std::cin.tie(0);

    std::cout.tie(0);

    string S;

    cin >> S;

    vector<long long> S_Hash(S.size()+1);

    S_Hash[0] = 0;

    for(long long i = 1; i <= S.size() ; i++){
        S_Hash[i] = (S_Hash[i-1]* 27 + (S[i-1] - 'a' + 1)*27)%MOD;
    }


    string rev_S(S.size(),'0');
    reverse_copy(S.begin(),S.end(),rev_S.begin());

    vector<long long> rev_S_Hash(S.size()+1); 
    
    rev_S_Hash[0] = 0;

    for(long long i = 1; i <= S.size() ; i++){
        rev_S_Hash[i] = (rev_S_Hash[i-1]* 27 + (rev_S[i-1] - 'a' + 1)*27)%MOD;
    }
    
    int m;
    
    cin >> m;

    vector<long long> power(S.size()+1);
    power[0] = 1;
    for(long long i = 1 ; i<= S.size() ; i++){
        power[i] = power[i - 1] * 27 % MOD;
    }

    for(int _ = 0 ; _  <  m ; _++){
        // 编号是 1-based
        long long l1,r1,l2,r2;

        cin >> l1>>r1>>l2>>r2;

        if(r2 - l2 != r1 - l1){
            std::cout<<"No\n";
            continue;
        }


        l2 = S.size() - l2 + 1;
        r2 = S.size() - r2 + 1;

        if( ((S_Hash[r1] - S_Hash[l1-1]*power[r1-l1 + 1]%MOD)+MOD)%MOD   ==  ((rev_S_Hash[l2] - rev_S_Hash[r2-1]*power[l2-r2 + 1]%MOD)+ MOD)%MOD  ){
            std::cout<<"Yes\n";
        }else{
            std::cout<<"No\n";
        }
        
    }
    return 0;
}