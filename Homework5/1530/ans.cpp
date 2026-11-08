#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n ;
    cin >> n;
    unordered_set<string> words;

    string s;
    for(int i = 0 ;  i < n ; i ++){
        cin >> s;
        words.insert(s);
    }

    long long m;
    cin >> m;
    vector<string> article;

    
    
    long long ans = 0;
    unordered_map<string, int> cnt;

    for (int i = 0; i < m; i++) {
        cin >> s;

        if (words.count(s) > 0 && cnt[s] == 0) {
            ans++;
        }

        cnt[s]++;
        article.push_back(s);
    }

    long long covered = 0;
    long long min_length = article.size();


    long long l = 0;
    long long r = 0;
    unordered_map<string, int> have_seen;

    if(words.count(article[r]) > 0){
        covered ++;
        have_seen[article[r]] ++;
    }
    for(; r< m-1; ){
        // 右侧指针右移
        r ++ ;
        if(words.count(article[r]) > 0){
            if(have_seen[article[r]] == 0){
                //第一次见
                covered ++;
            }
            // 不是第一次，只弄一次。
            have_seen[article[r]] ++;
        }

        //每次执行，左指针都尝试移动，缩小 r
        while (covered == ans) {
            // 当前区间合法，尝试更新 min_length
            min_length = min(r- l +1LL , min_length);

            //从 have_seen 中移除 article[l]

            have_seen[article[l]] --;

            // 如果移除的是某个目标单词的最后一次出现  covered 应该减少
            if(have_seen[article[l]] == 0){
                covered --;
            }

            l ++;
        }
    }
    std::cout<<ans<<endl;
    std::cout<<min_length<<endl;
    return 0;
}