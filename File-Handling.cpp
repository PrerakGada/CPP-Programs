#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string s="hi";
    ofstream out ("users/"+s+".txt");

    out<<"Hello "<<s;

    return 0;
} 