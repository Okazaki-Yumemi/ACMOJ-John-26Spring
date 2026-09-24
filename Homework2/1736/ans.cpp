#include <iostream>
// todo: declarations if you need
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;

__gnu_cxx::rope<int> nums;

void add() {
    // todo: read and add the element
    int pos,element;
    cin>>pos>>element;
    nums.insert(pos,element);
}
void erase() {
    // todo: read the index and erase the element
    int pos;
    cin>>pos;
    nums.erase(pos - 1,1);
}

void (*func[3])( ) = { NULL,  add,  erase};
// add() is func[1](), and erase() is func[2]();

int main(){
    // todo: your main function.
    int n,m;
    cin>>n>>m;
    
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    for(int i = 0 ; i < m ; i++){
        int opt;
        cin>>opt;
        func[opt]();
        
    }

    for(int x:nums){
        cout<<x<<" ";
    }


}