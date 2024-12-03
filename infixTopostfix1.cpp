#include<bits/stdc++.h>
using namespace std;

int top;
string prefix;
char Stack[1001];
class stack_st{
public :
    void push(char s){
        top++;
        Stack[top]=s;
    }
    void pop(){
        top--;
    }
    char topp(){
        return Stack[top];
    }
    bool isOperand(char s){
        if((s>='A' && s<='Z') || (s>='a' && s<='z')){
            return true;
        }
        else{
            return false;
        }
    }
    int operation(char s){
        if(s==')'){
            return -1;
           }
        else if(s=='+' || s=='-'){
            return 1;
        }
        else if(s=='*' || s=='/'){
            return 2;
        }
        else if(s=='^'){
            return 3;
        }
    }
};
int main(){
    stack_st st;
    string str;
   // top++;
    Stack[top]=')';
    getline(cin,str);
    //reverse(str.begin(),str.end());
   // cout<<str;

    for(int i=str.size();i>=0;i--){
        if(str[i]==' ' || str[i]==','){
            continue;
        }
        else if(st.isOperand(str[i])){
            prefix += str[i];
        }
        else if(str[i]==')'){
            st.push(str[i]);
        }
        else if(str[i]=='('){
            while(Stack[top]!=')'){
                prefix += st.topp();
                st.pop();
            }
            st.pop();
        }
        else{
            while(Stack[top]!=')' && (st.operation(Stack[top]) >= st.operation(str[i]))){
                    prefix += st.topp();
                    st.pop();
            }
            st.push(str[i]);
        }
    }
    while(Stack[top] != ')' ){
            prefix += Stack[top];
            st.pop();
    }
    reverse(prefix.begin(),prefix.end());
    cout<<prefix;
}
