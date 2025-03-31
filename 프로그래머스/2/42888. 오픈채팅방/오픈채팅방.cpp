#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(string s){
    vector<string> a;
    
    stringstream its(s);
    string buffer;
    
    while(getline(its,buffer,' '))
        a.push_back(buffer);    
    
    return a;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> infor, user, chat;
    map<string,string> uid;

    for(int i=0; i<record.size(); i++){
        infor=split(record[i]);
        
        if(infor[0]=="Enter"){
            uid[infor[1]]=infor[2];
            user.push_back(infor[1]);
            chat.push_back("님이 들어왔습니다.");
        }
        else if(infor[0]=="Leave"){
            user.push_back(infor[1]);
            chat.push_back("님이 나갔습니다.");
        }
        else if(infor[0]=="Change"){
            uid[infor[1]]=infor[2];
        }
    }
    
    for(int i=0; i<chat.size(); i++)
        answer.push_back(uid[user[i]]+chat[i]);
    
    return answer;
}