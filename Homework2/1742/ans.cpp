#include <bits/stdc++.h>

std::string type,decl;
int pos = 0;

std::string name = "";
std::vector<std::string> desc;


void parseDecl(){
    int stars = 0 ;
    while(decl[pos] == '*'){
        stars++;
        pos++;
    }

    if(decl[pos] == '('){
        pos++;
        parseDecl();
        pos++;
    }else{
        while(pos < decl.size() && std::isalpha(decl[pos])){
            name += decl[pos];
            pos++;
        }
    }

    while(pos < decl.size() && decl[pos] == '['){
        desc.push_back("array of");
        pos +=2; //跳过俩
    }

    for(int i = 0 ; i< stars ; i++){
        desc.push_back("pointer to");
    }

}

int main(){
    std::cin>>type>>decl;

    parseDecl();
    std::cout<<name<<" is";

    for(const std::string& s : desc){
        std::cout<<" "<<s;
    }

    std::cout<<" "<<type<<"\n";

}