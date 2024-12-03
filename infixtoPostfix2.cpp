#include<bits/stdc++.h>
using namespace std;

char Stack[1001],top;
string postfix = "";
class stack_st{
public :
    void push(char val){
        top++;
        Stack[top]=val;
    }

    void pop(){
        top--;
    }

    char topp(){
        return Stack[top];
    }

    bool isOperand(char s){
        if((s>='A' && s<='Z') || (s>='a' && s<='z'))
            return true;
        else
            return false;
    }

    int operation(char s){
       // push(s);
        if(s=='('){
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
int main()
{
    stack_st st;    //Creating object
    string str;     // a+(b*c-(d/e^f)*g)*h
    getline(cin,str);
    int k=0;
    st.push('(');
    for(int i=0;i<str.size();i++){
        if(str[i]==' ' || str[i]==','){
            continue;
        }
        else if(st.isOperand(str[i])){
            postfix += str[i];
        }
        else if(str[i]=='('){
            st.push('(');
        }
        else if(str[i]==')'){
            while(st.topp()!='('){
                    postfix +=st.topp();
                    st.pop();
                  }
            st.pop();
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
            while(Stack[top]!='(' && (st.operation(Stack[top])>=st.operation(str[i]))){
                postfix +=st.topp();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(Stack[top]!='('){
        postfix +=st.topp();
        st.pop();
    }
        cout<<postfix;
}
