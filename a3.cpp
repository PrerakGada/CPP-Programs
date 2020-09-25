#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Roll Number: 1981012"<<endl;

    cout<<"Enter a String: ";
    getline(cin, s);
    int len = s.size();
    
    int TokenCount = 1;
    string token = "";
    for(int i=0;i<len;i++)
    {
        if (s[i] != ' ')
            token += s[i];
        else
        {
            cout<<"Token"<<TokenCount<<" = "<<token;

            if(token == "asm" || token == "auto" || token == "bool" || token == "break"
            || token == "case" || token == "catch" || token == "char" || token == "class"
            || token == "const" || token == "continue" || token == "default" || token == "delete"
            || token == "do" || token == "double" || token == "else" || token == "enum"
            || token == "explicit" || token == "export" || token == "extern" || token == "false"
            || token == "float" || token == "for" || token == "friend" || token == "goto"
            || token == "if" || token == "inline" || token == "int" || token == "long"
            || token == "mutable" || token == "namespace" || token == "new" || token == "operator"
            || token == "private" || token == "protected" || token == "public" || token == "register"
            || token == "return" || token == "short" || token == "signed" || token == "sizeof"
            || token == "static" || token == "struct" || token == "switch" || token == "template"
            || token == "this" || token == "throw" || token == "true" || token == "try"
            || token == "typedef" || token == "typeid" || token == "typename" || token == "union"
            || token == "unsigned" || token == "using" || token == "virtual" || token == "void"
            || token == "volatile" || token == "wchar_t" || token == "while")
                cout<<" is a Keyword"<<endl;
            
            else if(token == "+" || token == "-" || token == "/" || token == "*"
            || token == "%" || token == "++" || token == "=" || token == "--"
            || token == "==" || token == "+=" || token == "-=" || token == "*="
            || token == "/=" || token == "%=" || token == "&=" || token == "|="
            || token == "^=" || token == ">=" || token == "<=" || token == "!="
            || token == ">" || token == "<" || token == "<<=" || token == ">>="
            || token == "&&" || token == "||" || token == "!")
                cout<<" is an Operator"<<endl;

            else
                cout<<" is Invalid"<<endl;

            token = "";
            TokenCount++;
        }
        
    }
    cout<<"Token"<<TokenCount<<" = "<<token<<endl;

    cout<<endl;
    return 0;
} 