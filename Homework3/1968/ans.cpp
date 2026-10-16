#include <bits/stdc++.h>

char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
    return x*f;
}

int main(){
    int n = read();
    int ones = 0;
    int twos = 0;


    for(int i = 0 ; i < n ; i++){
        int x = read();
        // 进位
        twos |= ones&x;
        // 更新低位
        ones ^= x;
        // 统计变成11的地方
        int threes = ones & twos;
        
        ones &= ~ threes;
        twos &= ~ threes;
        
    }
    std::cout<<(twos | ones)<<'\n';
    return 0;
}