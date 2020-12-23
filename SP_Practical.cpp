#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    cout<<"Roll Number: 1981012"<<endl;

    string s;
    cout<<"Enter a String: ";
    getline(cin, s);
    int len = s.size();
    
    int c;
    cout<<"\n\n1.Generate Tokens on the Console\n2.Generate Tokens in a file"<<endl;
    cout<<"Choose an option: ";
    cin>>c;

    if(c==1)
    {
        cout<<"\n"<<endl;
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
    }

    else if(c==2)
    {
        string filename;
        cout<<"Enter the name of the file: ";
        cin>>filename;

        ofstream out (filename + ".txt");

        int TokenCount = 1;
        string token = "";
        for(int i=0;i<len;i++)
        {
            if (s[i] != ' ')
                token += s[i];
            else
            {
                out<<"Token"<<TokenCount<<" = "<<token<<endl;
                token = "";
                TokenCount++;
            }
        }
        out<<"Token"<<TokenCount<<" = "<<token<<endl;
    }

    else
    {
        cout<<"Invalid Option"<<endl;
    }   
    
    return 0;
} 