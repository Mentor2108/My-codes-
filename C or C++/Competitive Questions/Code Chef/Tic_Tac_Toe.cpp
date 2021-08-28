#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

using namespace std; //all win conditions
int win[8][3] = {{0, 1, 2},  //horizontal top row
                {3, 4, 5}, //horizontal middle row
                {6, 7, 8}, //horizontal bottom row
                {0, 3, 6}, //vertical left column
                {1, 4, 7}, //vertical middle column
                {2, 5, 8}, //vertical right column
                {0, 4, 8},  //diagonal one
                {2, 4, 6}}; //diagonal 2
int num_ = 0, num_x=0, num_o=0; //number of x and o; //number of underscores

bool isWin(char *a, char c) //check if O/X wins
{
    for (int i=0; i<8; i++)
        if (a[win[i][0]] == c &&
            a[win[i][1]] == c &&
            a[win[i][2]] == c )
            return true;
    return false;
}

int checkwin (char *a) //Checks for case 1 and case 2
{
    if (isWin(a, 'O')) //if O wins
    {
        if (isWin(a, 'X')) //if X also wnis
            return -1; //not possible so -1
        if (num_x == num_o)
            return 0; //only O wins, so it is possible
        else 
            return -1;
    }

    if (isWin(a, 'X')) //only X wins, sooo possible
    {
        if ((num_x - num_o) == 1)
            return 0;
        else 
            return -1; 
    }

    if (num_ == 0) //neither X nor O wins, and there r 0 underscores, so a draw
        return 0;

    return 1; //none of the cases, so the game will continue for atleast one more round
}
bool isValid(char a[9])
{
    for (int i=0; i<9; i++)
    {
        if (a[i]=='X') 
            num_x++;
        if (a[i]=='O') 
            num_o++;
        if (a[i] == '_')
            num_ ++;
    }
    if ((0 <= (num_x - num_o)) && ((num_x - num_o) <= 1)) //checks if number of x and o are always equal, one more or one less than each other
    {  
        return true; //it is valid
    }
    return false; //it is not valid
}

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {   
        num_ = 0;
        num_x = 0;
        num_o = 0; //number of x and o;
        char a[9];
        for (int i = 0;i<9;i++) //inputting 
        {
            cin>>a[i];
        }   

        if(!isValid(a)) //for not valid
        {
            printf("3\n"); //prints 3
            continue;
        }
        int x = checkwin(a); //goes to check who wins 
        if ( x == -1) //if both win, not valid again
        {
            printf("3\n");
        }
        else if (x == 0) //if only 1 wins or draw
        {
            printf("1\n");
        }
        else //game will continue
            printf("2\n");
        
    }
}

int main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    solve();

    return 0;
}   
