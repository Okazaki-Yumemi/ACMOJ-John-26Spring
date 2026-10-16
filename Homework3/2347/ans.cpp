#include <iostream>

char *p1,*p2,buf[10000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++)
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
    int x;
    for(int i = 0 ; i < n ; i++){
        x = read();
        ones ^= x;
        twos ^= (ones & x);
    }
    std::cout<<twos;
    return 0;
}