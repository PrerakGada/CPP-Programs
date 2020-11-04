#include<iostream>
#include<stdlib.h>
using namespace std;

//-----------------------------------TicTacToe------------------------------------------
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
    if (board[0] == board[1] && board[1] == board[2] && board[0]!= ' ')
    {
        g = false;
        if(board[0] == 'X')
            cout<<"X wins"<<endl;
        else if(board[0] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[3] == board[4] && board[4] == board[5] && board[5]!= ' ')
    {
        g = false;
        if(board[3] == 'X')
            cout<<"X wins"<<endl;
        else if(board[3] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[6] == board[7] && board[7] == board[8] && board[8]!= ' ')
    {
        g = false;
        if(board[6] == 'X')
            cout<<"X wins"<<endl;
            else if(board[6] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[0] == board[3] && board[3] == board[6] && board[0]!= ' ')
    {
        g = false;
        if(board[0] == 'X')
            cout<<"X wins"<<endl;
        else if(board[0] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[1] == board[4] && board[4] == board[7] && board[1]!= ' ')
    {
        g = false;
        if(board[1] == 'X')
            cout<<"X wins"<<endl;
        else if(board[1] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[2] == board[5] && board[5] == board[8] && board[8]!= ' ')
    {
        g = false;
        if(board[2] == 'X')
            cout<<"X wins"<<endl;
        else if(board[2] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[0] == board[4] && board[4] == board[8] && board[0]!= ' ')
    {
        g = false;
        if(board[0] == 'X')
            cout<<"X wins"<<endl;
        else if(board[0] == 'O')
            cout<<"O Wins"<<endl;
    }

    else if (board[2] == board[4] && board[4] == board[6] && board[2]!= ' ')
    {
        g = false;
        if(board[2] == 'X')
            cout<<"X wins"<<endl;
        else if(board[2] == 'O')
            cout<<"O Wins"<<endl;
    }

    else
    {
        g = false;
        for(int i=0;i<9;i++)
        {
            if(board[i] == ' ')
                g = true;
        }
        if(g == false)
            cout<<"The Game is Draw!"<<endl;
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

void TicTacToe() //TicTacToe driver code
{
    cout<<"\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9"<<endl;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool Game = true;
    int MoveCount = 0;
    char turn = 'X';
    tttdisplayboard(board);

    while(Game == true)
    {
        turn = tttplayer(turn, MoveCount);
        tttmove(turn, board);
        MoveCount++;
        tttdisplayboard(board);
        Game = tttWinLose(Game, board);
    }
}

//----------------------------------------HangMan----------------------------------------

void hmdisplay(string word, string hangman, string wrong, int c)
{

    cout<<"\n\n-----HangMan-----\n"<<endl;

    cout<<"Chances left: "<<c<<endl;
    cout<<"Attempted Alphabets: ";

    for(int i=0;i<wrong.length();i++)
        cout<<wrong[i]<<" ";
    cout<<endl;

    for(int i=0;i<hangman.length();i++)
        cout<<hangman[i]<<" ";
    cout<<endl;
}

void HangMan()
{
    string words[10] = {"encapsulation", "awesome", "floroscent", "enormity", "technique",
                        "polynomial", "difficult", "luggage", "eliminate", "rythm"};
    //string word = words[rand()%10];
    string word = "hey";
    int len = word.length();
    string wrong = "";
    string hangman = "";
    string flag = "t";
    int chances = 10;

    for(int i=0;i<len;i++)
        hangman += "-";
    
    while(chances>0 && word != hangman)
    {
        hmdisplay(word, hangman, wrong, chances);
        
        hmplay:
        char in;
        bool used = false;
        flag = "f";
        cout<<"Guess an Alphabet: ";
        cin>>in;

        for(int i=0; i<wrong.length();i++)
        {
            if(wrong[i] == in)
                used = true;
        }

        if(used == false)
        {
            for(int i=0; i<word.length(); i++)
            {
                if(word[i] == in)
                {
                    hangman[i] = in;
                    flag = "t";
                }
            }
            if(flag == "f")
            {
                chances--;
                wrong += in;
            }
        }
        else
        {
            cout<<"That alphabet is already guessed!\n"<<endl;
            hmdisplay(word, hangman, wrong, chances);
            goto hmplay;
        }
    }
    if(hangman == word)
        cout<<"Congratulaitons, You won!!"<<endl;
    else
        cout<<"Your chances are over, Better luck next time.\nThe word was: "<<word<<endl;
}

//---------------------------------------Restaurant---------------------------------------


// ---------------------------------------Main Code--------------------------------------
int main()
{

    HangMan();

    return 0;
} 