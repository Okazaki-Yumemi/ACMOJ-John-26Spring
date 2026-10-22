#include<bits/stdc++.h>
#include<sstream>
using namespace std;


struct Student
{
    string original;
    vector<string> scores;
};

int main(){

    int n;
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    cin >> s;


    //处理Head
    string head = s;
    unordered_map<string,int> col;
    stringstream ss(s);
    string header;
    vector<string> Headers;

    while(getline(ss,header,',')){
        Headers.push_back(header);
    }
    // 建立映射
    for(int i = 0 ; i < Headers.size(); i++){
        col[Headers[i]] = i;
    }


    vector<Student> grades;
    for(int i = 0 ; i < n - 1 ; i ++){
        //处理数据
        cin >> s;
        Student student;
        student.original = s;
        string filed ;
        vector<string>fileds;
        stringstream row_stream(s);
        while(getline(row_stream,filed,',')){
            fileds.push_back(filed);
        }
        student.scores = fileds;
        grades.push_back(student);
    }

    int m;
    cin >> m;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> rules;
    for(int i = 0 ; i < m ; i++){
        cin >> s;
        rules.push_back(s);
        
    }

    for(int i = rules.size() - 1; i >= 0 ; i--){
        string s = rules[i];
        char direction = s.back();
        string name = s.substr(0,s.size() - 1);

        int index = col[name];
        bool ascending = (direction == '+')? true:false;

        auto cmp = [&](const Student& a,const Student&b){
            if(index >= 1){
                int x = stoi(a.scores[index]);
                int y = stoi(b.scores[index]);
                if(ascending){
                    return x < y;
                }else{
                    return x > y;
                }
                
            }else{
                string x = a.scores[index];
                string y = b.scores[index];
                if(ascending){
                    return x < y;
                }else{
                    return x > y;
                }
            }
        };
        stable_sort(grades.begin(),grades.end(),cmp);  
    }


    std::cout<< head<<endl;
    for(int i = 0 ; i < grades.size(); i++){
        std::cout<<grades[i].original<<endl;
    }
    return 0;

}
