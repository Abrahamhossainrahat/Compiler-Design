#include<bits/stdc++.h>
#include <type_traits>
using namespace std;

vector<string> keywords = {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break",
"case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", 
"const", "consteval", "constexpr", "const_cast", "continue", "co_await", "co_return", 
"co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", 
"enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", 
"if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", 
"not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", 
"register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", 
"static", "static_assert", "static_cast", "struct", "switch", "template", "this", 
"thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", 
"unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};

vector<string>operators = {"+","-","*","/","%","==","!=","<",">","<=",">=","&&","||","!","&","|","^","~","<<",">>","=","+=","-=","*=","/=","%=","&=","|=","^=","<<=",">>=","++","--","?",":",".","->","*","&","(type)","static_cast<>","dynamic_cast<>","const_cast<>","reinterpret_cast<>","sizeof","typeid","::",".*","->*","!","~"};

// Function work
bool isKeyword(string token){
    for(auto &keyword : keywords){
        if(keyword == token) return true;
    }
    return false;
}
bool isIdentifier(string token){
    //char ch = tolower(token[0]);
    if(!(token[0]=='_' || isalpha(token[0]))) return false;
    for(int i=1; i<token.size(); i++){
        if(!(token[i]=='_' || isalnum(token[i]))) return false;
    }
    return true;
}

bool isOperator(string token){
    for(auto &op : operators){
        if(op == token) return true;
    }
    return false;
}
// function to function calling
bool isInt(string token){
    for(int i=0;i<token.length();i++){
        if(!(isdigit(token[i]))) return false;
    }
    return true;
}

bool isFloat(string token){
    int cnt = 0;
    int dotCount = count(token.begin(), token.end(), '.');
    for(int i=dotCount-1; i>=0; i--){
        if(!isdigit(token[i])) return false;
    }
    for(int i= dotCount + 1; i<token.length(); i++){
        if(!isdigit(token[i])) return false;
        cnt = 1;
    }
    if(dotCount==1 && cnt==1){
        return true;
    }
    return false;
}
bool isString(string token){
    if(token[0]=='"' && token[token.length()-1]=='"') return true;
    return false;
}
bool isChar(string token){
    if(token[0]=='\'' && token[token.length()-1]=='\''){
        if(token.length()==3)
            return true;
    }
    return false;
}
bool isConstant(string token){
    if(isInt(token)) return true;
    if(isFloat(token)) return true;
    if(isString(token)) return true;
    if(isChar(token)) return true;
    return false;
}

int main(){
    // string str =" ==>= @";
    // cout<<str<<endl;
    freopen("07.txt","r",stdin);
    string word;
    while(getline(cin,word)){
        if(isKeyword(word)){
            cout << word << " : keyword" << endl;
        }
        else if(isIdentifier(word)){
            cout << word << " : Identifier" << endl;
        }
        else if(isOperator(word)){
            cout << word << " : Operator" << endl;
        }
        else if(isConstant(word)){
            cout << word << " : Constant" << endl;
        }
        else{
            cout << word << " : Unknown" << endl;
        }
    }
}