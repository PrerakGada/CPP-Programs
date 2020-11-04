#include<iostream>
using namespace std;

void tttdisplayboard(char board[9])
{
    cout<<"\n";
    cout<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<endl;
    cout<<"-+-+-"<<endl;
    cout<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<endl;
    cout<<"-+-+-"<<endl;
    cout<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<endl;
    cout<<"\n"<<endl;
}

bool tttWinLose(bool g, char board[9])
{
    if (board[0] == board[1] == board[2] && board[0]!= ' ')
    {
        g = false;
        if(board[0] == 'X')
            cout<<"X wins"<<endl;
        else if(board[0] == 'O')
            cout<<"O Wins"<<endl;
    }
    return g;
}

char tttmove(char t, char board[9])
{
    tttmove:
    int pos;
    cout<<"Enter the location you want to play: ";
    cin>>pos;

    if(board[pos-1] == ' ')
        board[pos-1] = t;
    else
    {
        cout<<"The place is already filled"<<endl;
        goto tttmove;
    }

    return board[9];
}

char tttplayer(char t, int mc)
{
    if(mc % 2 == 0)
    {
        cout<<"It's X's Turn"<<endl;
        t = 'X';
    }
    else
    {
        cout<<"It's O's Turn"<<endl;
        t = 'O';
    }
    return t;
}

void TicTacToe()
{
    cout<<"\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9"<<endl;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool Game = true;
    int MoveCount = 0;
    char turn = 'X';
    tttdisplayboard(board);
}

int main()
{

    TicTacToe();

    return 0;
} 