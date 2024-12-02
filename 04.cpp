#include<bits/stdc++.h>
using namespace std;

bool isVariable(string token){
    char ch = tolower(token[0]);
    if (token.empty()) return false;
    else if(!(ch >= 'i' && ch <= 'n')){
        return false;
    }
    for(int i=1; i<token.length(); i++){
        if(!(isalnum(token[i]))){
            return false;
        }
    }
    return true;
}

bool isInt(string token){
    if (token.empty()) return false;
    else if(!(isdigit(token[0]) && token[0] != '0'))
        return false;
        
    for(int i=1; i<token.length(); i++){
        if(!(isdigit(token[i])))
            return false;
    }
    return true;
}

int main(){
    freopen("04.txt", "r", stdin);
    if (!freopen("04.txt", "r", stdin)) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }
   // freopen("04.txt", "w", stdout);
    string word;
    while(getline(cin, word)){
        if(isVariable(word)){
            cout<<word<<" : Integer Variable"<<endl;
        }
        else if(isInt(word)){
            if(word.length()<=4)
                cout<<word<<" : ShortInt Number"<<endl;
            else{
                cout<<word<<" : LongInt Number"<<endl;
            }
        }
        else{
            cout<<word<<" : Invalid Input"<<endl;
        }
        
    }
}