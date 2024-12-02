#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "Munmun is the student of Computer Science & Engineering",str1[100],vowelWordarr[100],consonantWordarr[100];
    int vowels = 0, consonants = 0,startIndex = 0,wordIndex =0,previousIndex = 0,vwai = 0, cwai = 0;
    char vowelsarr[100], consonantsarr[100];

    for(int i=0;i<str.length();i++){
        if(isspace(str[i])){
            if(previousIndex != 0){
                str1[wordIndex] = str.substr(startIndex, i- previousIndex - 1);
            }
            else{
                str1[wordIndex] = str.substr(startIndex, i);
            }
            startIndex = i+1;
            previousIndex = i;
            wordIndex++;
        }
        if(isalpha(str[i])){
            //char lower = tolower(str[i]);
            if(tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u'){
                vowelsarr[vowels] = str[i];
                vowels++;
            }
            else{
                consonantsarr[consonants] = str[i];
                consonants++;
            }
        }
    }
    str1[wordIndex] = str.substr(previousIndex+1, str.length());
    wordIndex++;

    // 2 array generate using check words start with vowel or consonant
    for(int i=0;i<wordIndex;i++){
        string check = str1[i];
        if(tolower(check[0]) == 'a' || tolower(check[0]) == 'e' || tolower(check[0]) == 'i' || tolower(check[0]) == 'o' || tolower(check[0]) == 'u'){
            vowelWordarr[vwai] = str1[i];
            vwai++;
        }
        else if(ispunct(check[0])){
            continue; // skip punctuation words
        }
        else{
            consonantWordarr[cwai] = str1[i];
            cwai++;
        }
        
    }
    
    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;

    cout << "Vowels: ";
    for(int i=0;i<vowels;i++){
        cout << vowelsarr[i] << " ";
    }
    
    cout << "\nConsonants: ";
    for(int i=0;i<consonants;i++){
        cout << consonantsarr[i] << " ";
    }
    
    // print all words from given string
    // cout<<"\nWords: ";
    // for(int i=0;i<wordIndex;i++){
    //     cout << str1[i] <<endl;
    // }
    // print vowel words
    cout << "\nVowel Words: ";
    for(int i=0;i<vwai;i++){
        cout << vowelWordarr[i] << " ";
    }
    // print consonant words
    cout << "\nConsonant Words: ";
    for(int i=0;i<cwai;i++){
        cout << consonantWordarr[i] << " ";
    }
    
    return 0;
}