#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream out ("NOTES.txt");

    for(int i=1;i<=100;i++)
        out<<i<<endl;

    return 0;
}