#include<bits/stdc++.h>
using namespace std;
bool isVariable(string token){
    if(token.empty()) return false;
    char ch = tolower(token[0]);
    if(!((ch >= 'a' && ch <= 'h') || (ch >= 'o'&& ch <= 'z'))) return false;
    for(int i=1; i<token.length();i++){
        if(!isalnum(token[i])) return false;
    }
    return true;
}

bool isNum(string token){
    int cnt =0;
    // if((token[0] == '0' && token[1] == '.')){
    //     for(int i=0;i<token.length();i++){
    //         if(!isdigit(token[i])) return false;
    //     }
    //     //return true;
    // }
    if(token[0] == '1' || (token[0] == '0' && token[1] == '.')){
        size_t dotPosition = token.find('.');
         //cout<<"sizedot :"<<token<<" : "<<dotPosition<<endl;
        int dotCount = count(token.begin(), token.end(), '.');
        if(dotCount> 1) return false;
        for(int i = dotPosition - 1; i >= 0; i--){
            if(!isdigit(token[i])) return false;
        }
        for(int i = dotPosition+1; i< token.length(); i++){
            cnt++;
            if(!isdigit(token[i])) return false;
        }       
       
    }
    
    if(cnt==2)
        cout<<token<<" : Float Number"<<endl;
    else if(cnt>2)
        cout<<token<<" : Double Number"<<endl;
    else
        cout<<token<<" : Invalid Input"<<endl;
        
    return true;
}

int main(){
    freopen("05.txt", "r", stdin);
    string word;
    while(getline(cin, word)){
        if(isVariable(word)){
            cout<<word<<" : Float variable"<<endl;
        }
        else if(isNum(word)){
            continue;
        }
        else{
            cout<<word<<" : Invalid Input"<<endl;
        }
        
    }
}