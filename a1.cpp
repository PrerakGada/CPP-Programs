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
            cout<<"Token"<<TokenCount<<" = "<<token<<endl;
            token = "";
            TokenCount++;
        }
    }
    cout<<"Token"<<TokenCount<<" = "<<token<<endl;

    cout<<endl;
    return 0;
} 