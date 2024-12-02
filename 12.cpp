#include<bits/stdc++.h>
using namespace std;

bool isInt(string token){
    if(token.empty()) return false;
    for(auto ch : token)
        if(!isdigit(ch))
            return false;
    return true;
}
bool isIdentifier(string token){
    if(token.empty()) return false;
    else if(!(token[0] == '_' || isalpha(token[0]))){
        cout<<"XHHU"<<endl;
        return false;
    }
    for(int i=1; i<token.size();i++){
        if(!isalnum(token[i]) && token[i]!= '_'){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("012.txt","r",stdin);
    string input;
    while(getline(cin, input)){
        int operators = 0;
        vector<string> operands;
        string operand ;
        stack<char> stk;
        bool isvalid = true;

        for(auto ch : input){
            if(ch == '+' || ch == '-' || ch =='*' || ch == '/'){
                operators++;
                if(operand.size()){
                    operands.push_back(operand);
                    operand.clear();
                }
                else{
                    isvalid = false;
                    break;
                }
            }

            else{
                if(ch == '(' ){
                    if(operand.size()){
                        isvalid = false;
                        break;
                    }
                    stk.push(ch);
                }
                else if(ch == ')'){
                    if(operand.size() && !stk.empty()){
                        operands.push_back(operand);
                        operand.clear();
                        stk.pop();
                    }
                    else{
                        isvalid = false;
                        break;
                    }
                }
                else{
                    operand += ch;
                }
            }
        }
        if(operand.size()){
            operands.push_back(operand);
        }

        for(int i=0;i<operands.size();i++){
            if(!(isInt(operands[i]) || isIdentifier(operands[i]))){
                isvalid = false;
                break;
            }
        }

        if(isvalid && stk.empty() && operands.size() == operators + 1){
            cout <<input<< " : Valid expression" << endl;
        }
        else{
            cout << input<< " : Invalid expression" << endl;
        }
    }

}