#include<bits/stdc++.h>
using namespace std;
int main(){
    string str = "Md. Tareq Zaman, Part-3, 2011";
    int words = 0, letters = 0, digit = 0, characters = 0,digitarr[100];
    char lettrtsarr[100],chararr[100];
    for(int i=0;i<str.length();i++){
        
        if(isalpha(str[i])){
            lettrtsarr[letters] = str[i];
            letters++;
        }
        else if(isspace(str[i])){
            words++;
           // characters++;
        }
        else if(isdigit(str[i])){
            digitarr[digit] = str[i] - '0';
            digit++;
           // characters++;
        }
        else{
            chararr[characters] = str[i];
            characters++;
        }
    }
    
    cout << "Total letters: " << letters << endl;
    cout << "Total words: " << words + 1 << endl;
    cout << "Total digits: " << digit << endl;
    cout << "Total characters: " << characters << endl;
    cout << "Alphabetic characters: ";
    for(int i=0;i<letters;i++){
        cout<<lettrtsarr[i]<<" ";
    }
    cout << "\nDigits: ";
    for(int i=0;i<digit;i++){
        cout<<digitarr[i]<<" ";
    }
    cout << "\nSpecial characters: ";
    for(int i=0;i<characters;i++){
        cout<<chararr[i]<<" ";
    }
    return 0;
}