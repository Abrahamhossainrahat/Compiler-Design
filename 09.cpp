#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

vector<string>first ={"Sagor", "Selim", "Salma", "Nipu","he", "she", "I", "we", "you", "they"};
//vector<string>p = {"he", "she", "I", "we", "you", "they"};
vector<string>second = {"read", "eat", "take", "run", "write"};
vector<string>third = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

int main(){
    freopen("09.txt", "r", stdin);
    string input;
    while(getline(cin,input)){
        string word;
        //cout<<input<<endl;
        vector<string> words;
        stringstream s(input);
        while(s >> word){
            words.push_back(word);
        }
        bool isvalid = true;

        if(words.size()<2 && words.size()>3) 
            isvalid = false;
        else{
            if(find(first.begin(), first.end(), words[0]) == first.end()) 
                isvalid = false;
            else if(find(second.begin(), second.end(), words[1]) == second.end())
                isvalid = false;
            
            else if(isvalid && words.size()==3 && find(third.begin(), third.end(), words[2]) == third.end()) 
                isvalid = false;
        }
        if(isvalid) cout<<input<<" : Valid"<<endl;
        else cout<<input<<" : Invalid"<<endl;
    }  
}