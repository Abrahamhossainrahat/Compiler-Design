#include<bits/stdc++.h>
using namespace std;
bool isCharVariable(string token){
    if(!(token[0]=='c' && token[1]=='h' && token[2]=='_'))
        return false;
    for(int i=3; i<token.length(); i++){
        if(!isalnum(token[i]))
            return false;
    }
    return true;
}
bool isBinaryVariable(string token){
    if(!(token[0]=='b' && token[1]=='n' && token[2]=='_'))
        return false;
    for(int i=3; i<token.length(); i++){
        if(!isalnum(token[i]))
            return false;
    }
    return true;
}

bool isBinaryNum(string token){
    if(!(token[0]=='0' && (token[1]=='0' || token[1]=='1')))
        return false;
    for(int i=2; i<token.length(); i++){
        if(!(token[i]=='0' || token[i]=='1'))
            return false;
    }
    return true;
}

int main(){
    freopen("06.txt", "r", stdin);
    string word;
    while(getline(cin, word)){
        if(isCharVariable(word)){
            cout<<word<<" : Character variable "<<endl;
        }
        else if(isBinaryVariable(word)){
            cout<<word<<" : Binary variable "<<endl;
        }
        else if(isBinaryNum(word)){
            cout<<word<<" : Binary number "<<endl;
        }
        else{
            cout<<word<<" : Undefined "<<endl;
        }

    }
}
