#include<iostream>
using namespace std;

char arr[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char turn = 'x';
int row, col;
bool draw = false;

void display()
{
    system("cls");
    cout<<"T I C K   T A C   T O E   G A M E\n"<<endl;
    cout<<"Player 1 [x]"<<endl;
    cout<<"Player 2 [o]\n\n "<<endl;
    cout<<"\t\t _________________\n";
    cout<<"\t\t|     |     |     |\n";
    cout<<"\t\t|  "<<arr[0][0]<<"  |  "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  |\n";
    cout<<"\t\t|_____|_____|_____|\n";
    cout<<"\t\t|     |     |     |\n";
    cout<<"\t\t|  "<<arr[1][0]<<"  |  "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  |\n";
    cout<<"\t\t|_____|_____|_____|\n";
    cout<<"\t\t|     |     |     |\n";
    cout<<"\t\t|  "<<arr[2][0]<<"  |  "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  |\n";
    cout<<"\t\t|_____|_____|_____|\n";
}

void player_turn()
{
    int choice;

    if(turn == 'x')
        cout<<"\nPlayer 1 [x] turn : ";

    if(turn == 'o')
        cout<<"\nPlayer 2 [o] turn : ";

    cin>>choice;
    switch(choice)
        {
           case 1: row=0; col= 0; break;
           case 2: row=0; col= 1; break;
           case 3: row=0; col= 2; break;
           case 4: row=1; col= 0; break;
           case 5: row=1; col= 1; break;
           case 6: row=1; col= 2; break;
           case 7: row=2; col= 0; break;
           case 8: row=2; col= 1; break;
           case 9: row=2; col= 2; break;

            default:
                cout<<"Invalid choice";
                break;
        }

        if(turn == 'x' && arr[row][col]!='x' && arr[row][col]!='o' )
        {
            arr[row][col] = 'x';
            turn = 'o';
        }
        
        else if(turn == 'o' && arr[row][col]!='x' && arr[row][col]!='o')
        {
            arr[row][col] = 'o';
            turn = 'x';
        }
        else
        {
            cout<<"\nBox already filled, try again!";
        }

        display();
}

bool gameover()
{   //check if someone won row or col wise
    for (int i = 0; i < 3; i++)
        if((arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) || (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]))
            return false;

    //check for diagonal win
    for (int i = 0; i < 3; i++)
    {
        if((arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) || arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
        return false;
    }
   
    //game going
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
             if(arr[i][j] != 'x' && arr[i][j]!= 'o')
                return true;

    //game draw condition
    draw = true;
    return false;
    
}

void instruction(void)
{
    cout<<"1. The game is played on a grid that's 3 squares by 3 squares.\n2. You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares.\n3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.";
}

int main()
{
    int ch;
    cout<<"***Choose from the below options***"<<endl;
    cout<<"1. Play Game"<<endl;
    cout<<"2. Read Instructions"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            while(gameover())
            {
                display(); 
                player_turn();
            }

            if(turn=='x' && draw==false)
                cout<<"\nPlayer 2 [o] WINS!!";

            else if(turn=='o' && draw==false)
                cout<<"\nPlayer 1 [x] WINS!!";
            
            else
                cout<<"\n\tGAME DRAW!!";
            
            break;

        case 2:
            instruction();
            break;

        case 3:
            break;

        default:
            cout<<"Enter valid choice";

    }
    return 0;
}