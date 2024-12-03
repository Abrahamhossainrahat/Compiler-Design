#include<bits/stdc++.h>
using namespace std;

void shift(string stk , string input){
    cout<<stk<<"\t"<<input<<"\t\tShift"<<endl;
}
void reduce(string stk, string input , char left , char right){
    cout<<stk<<"\t"<<input<<"\t\tReduce "<<left<<" -> "<<right<<endl;
}

int main(){
    int n;
    string input;
    cin >> n;
    cout<<"Enter the string : ";
    cin>>input;
    freopen("10.txt", "r", stdin);
    string word;
    //cout<<n<<"jfhdjfhdjh";
    cin.ignore();
    string g_left[n], g_right[n];  
    for(int i=0;i<n;i++){
        getline(cin, word);
        g_left[i] = word[0];
        for(int j=3;j<word.length();j++){
            g_right[i] += word[j];
        }
    }
    cout<<"Grammer : "<<endl;
    for(int i=0;i<n;i++){
        cout<<g_left[i]<<" -> "<<g_right[i]<<endl;
    }
    // string input;
    // cout<<"Enter the string : ";
    // cin>>input;
    cout<<"\nStack\tInput\t\tAction\n";
    string stk = "$";
    input.push_back('$');

    while(input != "$"){
        stk.push_back(input[0]);
        input.erase(input.begin());
        shift(stk, input);
        for(int i=0;i<n;i++){
            bool reduceok = false;
            if(stk.find(g_right[i]) < stk.size()){
                stk.erase(stk.find(g_right[i]), stk.length());
                stk += g_left[i];
                reduce(stk, input, g_left[i][0], g_right[i][0]);
                reduceok = true;
            }
            if(reduceok) i = -1;
        }
        
    }




    return 0;
}
