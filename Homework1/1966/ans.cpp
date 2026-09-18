#include <bits/stdc++.h>
using namespace std;


int main(){
    int t ;
    vector<int> ans_s;
    cin >> t;

    for(int i = 0 ; i < t; i++){
        int a1, b1, c1;
        int a2, b2, c2;
        scanf("%d-%d-%d %d-%d-%d",
            &a1,&b1,&c1,
            &a2,&b2,&c2);
        
        if(a1 > a2 ||
            (a1==a2 && b1 > b2) ||
            (a1 == a2 && b1 == b2 && c1 > c2)){

                swap(a1,a2);
                swap(b1,b2);
                swap(c1,c2);
            }

        int yr_run = 0, yr_not_run = 0;
        for(int i = a1; i < a2 ; i++){
            if(i % 4 == 0){
                yr_run++;
            }else{
                yr_not_run++;
            }
        }

        int days_1 = 0, days_2 = 0;
        for(int i = 1; i < b1; i++){
            // 二月
            if(i == 2){
                // date 1 是闰年
                if(a1 % 4 == 0){
                    days_1 += 29;
                }else{
                    days_1 += 28;
                }
                continue;
            }
            // 前半年
            if(i <= 7){
                // 奇数，大月
                if(i % 2){
                    days_1 += 31;
                }else{
                    days_1 += 30;
                }
            }else{
                //后半年
                if(i % 2){
                    days_1 += 30;
                }else{
                    days_1 += 31;
                }
            }
        }
        //date2
        for(int i = 1; i < b2; i++){
            // 二月
            if(i == 2){
                // date 2 是闰年
                if(a2 % 4 == 0){
                    days_2 += 29;
                }else{
                    days_2 += 28;
                }
                continue;
            }
            // 前半年
            if(i <= 7){
                // 奇数，大月
                if(i % 2){
                    days_2 += 31;
                }else{
                    days_2 += 30;
                }
            }else{
                //后半年
                if(i % 2){
                    days_2 += 30;
                }else{
                    days_2 += 31;
                }
            }
        }
        days_1 += c1;
        days_2 += c2;
        //
        int ans = 0;
        ans = yr_run * 366 + yr_not_run * 365 + days_2 - days_1;

        ans_s.push_back(ans);
    }

    for(int c:ans_s){
        cout<<c<<endl;
    }
    return 0;
}