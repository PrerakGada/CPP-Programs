#include<iostream>
using namespace std;

int main()
{
    cout<<"Roll Number: 1981012"<<endl;

    string s;

    cout<<"Enter a String: ";
    cin>>s;

    int len = s.size();

    for(int i=0;i<len;i++)
    {
        if(s[i] == '+')
            cout<<s[i]<<" = Operator"<<endl;
        else if(s[i] == '-')
            cout<<s[i]<<" = Operator"<<endl;
        else if(s[i] == '/')
            cout<<s[i]<<" = Operator"<<endl;
        else if(s[i] == '*')
            cout<<s[i]<<" = Operator"<<endl;
        else if(s[i] == '%')
            cout<<s[i]<<" = Operator"<<endl;
        else if(s[i] == '^')
            cout<<s[i]<<" = Operator"<<endl;
        else if(s[i] == '=')
            cout<<s[i]<<" = Operator"<<endl;
        else if(isalpha(s[i]))
            cout<<s[i]<<" = Alphabet"<<endl;
        else if(isdigit(s[i]))
            cout<<s[i]<<" = Digit"<<endl; 
        else
            cout<<s[i]<<" = Special Character"<<endl; 
    }

    cout<<endl;
    return 0;
} 