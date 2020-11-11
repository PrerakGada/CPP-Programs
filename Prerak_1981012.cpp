#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

string Bill[100] = {};
double aBill = 0;

void TicTacToe(void);
void HangMan(void);
void Games(void);
void MainMenu(void);
void Restaurant(void);
void CheckOut(void);
void LoginSignup(void);
void Login(void);
void Signup(void);


//-----------------------------------TicTacToe------------------------------------------
void tttdisplayboard(char board[9])
{
    cout<<"\n-------TicTacToe-------"<<endl;
    cout<<"\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9"<<endl;
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
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool Game = true;
    int MoveCount = 0;
    char turn = 'X';

    while(Game == true)
    {
        system("clear");
        tttdisplayboard(board);
        turn = tttplayer(turn, MoveCount);
        tttmove(turn, board);
        MoveCount++;

        tttdisplayboard(board);
        Game = tttWinLose(Game, board);
    }
    int a;
    cout<<"\n\n\nDo you want to play again?"<<endl;
    cout<<"Enter 1 for yes: ";
    cin>>a;
    if(a==1)
        TicTacToe();
}

//----------------------------------------HangMan----------------------------------------

void hmdisplay(string word, string hangman, string wrong, int c)
{

    cout<<"\n-------HangMan-------\n"<<endl;

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
    string words[10] = {"encapsulation", "awesome", "floroscent", "enormity", "technique", "polynomial", "difficult", "luggage", "eliminate", "rythm"};
    //string word = words[rand()%10];
    string word = "hey";
    int len = word.length();
    string wrong = "";
    string hangman = "";
    string flag = "t";
    int chances = 2;

    for(int i=0;i<len;i++)
        hangman += "-";
    
    while(chances>0 && word != hangman)
    {
        system("clear");
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
    {
        system("clear");
        hmdisplay(word, hangman, wrong, chances);
        cout<<"\n\nCongratulaitons, You won!!"<<endl;
    }
    else
        cout<<"\n\nYour chances are over, Better luck next time.\n\nThe word was: "<<word<<endl;
    
    int a;
    cout<<"\n\n\nDo you want to play again?"<<endl;
    cout<<"Enter 1 for yes: ";
    cin>>a;
    if(a==1)
        HangMan();
}

//---------------------------------------Restaurant---------------------------------------


void rmeal()
{
    cout<<"1.Rice\n2.Roti\n3.Daal"<<endl;
}

void rfastfood()
{
    cout<<"1.Pizza\n2.Sandwich\n3.Burger"<<endl;
}

void rdd()
{
    cout<<"1.Nutella\n2.Gola\n3.Ice-Cream\n4.Breezer\n5.RedBull"<<endl;
}

void Restaurant()
{
    system("clear");
    cout<<"Welcome to The Great Indian Resort's Restaurant!!"<<endl;

    int c;

    cout<<"1.Meal\n2.Fast Food\n3.Deserts and Drinks"<<endl;

    cout<<"Enter your choice: ";
    cin>>c;
    switch(c)
    {
        case 1:
            rmeal();
            break;

        case 2:
            rfastfood();
            break;

        case 3:
            rdd();
            break;

        default:
            Restaurant();
            break;

    }
}

void Games()
{
    system("clear");
    int choice;
    cout<<"-------------------------------"<<endl;
    cout<<"|            Games            |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"| 1.TicTacToe                 |"<<endl;
    cout<<"| 2.HangMan                   |"<<endl;
    cout<<"|                             |"<<endl;
    cout<<"| 0.Main Menu                 |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        TicTacToe();
        break;

    case 2:
        HangMan();
        break;

    case 0:
        MainMenu();
        break;
    
    default:
        Games();
        break;
    }

}

void CheckOut()
{
    system("clear");

}

void LoginSignup()
{
    system("clear");
    int choice;
    cout<<"-------------------------------"<<endl;
    cout<<"|       Login or Sign Up      |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"| 1.Login                     |"<<endl;
    cout<<"| 2.Sign Up                   |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        Login();
        break;

    case 2:
        Signup();
        break;

    default:
        LoginSignup();
        break;
    }
}

void Login()
{
    system("clear");
}

void Signup()
{
    system("clear");
    string uname;
    cout<<"Enter your Name: ";
    cin>>uname;

    ofstream out ("users/"+uname+"_data.txt");
    ofstream ot ("users/"+uname+"_bill.txt");
    
}

void MainMenu()
{
    system("clear");
    int choice;
    cout<<"-------------------------------"<<endl;
    cout<<"|          Main Menu          |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"| 1.Play Games                |"<<endl;
    cout<<"| 2.Restaurant                |"<<endl;
    cout<<"|                             |"<<endl;
    cout<<"| 0.Check Out                 |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        Games();
        break;

    case 2:
        Restaurant();
        break;

    case 0:
        int c;
        system("clear");
        cout<<"-------------------------------"<<endl;
        cout<<"|            Alert!           |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Are you sure you want to Check Out?"<<endl;
        cout<<"Enter 1 for yes: ";
        cin>>c;
        if(c==1)
            CheckOut();
        else 
            MainMenu();
        break;
    
    default:
        MainMenu();
        break;
    }
}
// ---------------------------------------Main Code--------------------------------------
int main()
{
    //MainMenu();
    LoginSignup();
    return 0;
}