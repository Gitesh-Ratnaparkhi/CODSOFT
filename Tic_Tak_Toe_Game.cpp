#include <iostream>
#include <vector>
using namespace std;

// In first apporach we are using the vector
// This is the function which display the vector
void display_game(vector<vector<char>> &Game_board){
    for (int i = 0; i < Game_board.size(); i++){
        for (int j = 0; j < Game_board[i].size(); j++){
            cout << Game_board[i][j]<<" ";
        }cout<<endl;
    }
}

// This is the function which check the board weather it is empty or not 
bool check_completet_board(vector<vector<char>> &Game_board){
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            if (Game_board[i][j] == ' ')return false;
        }
    }
    return true;
}

// This is the function which check weather the player win or defeat.
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)return true; 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)return true;
    return false;
}

// This is the function which start the game
void Tic_Tak_Game(){
    vector<vector<char>> Game_board(3,vector<char>(3, ' '));
    char player = 'X';
    bool match_win = false;
    bool match_draw = false;
    cout<<"Welcome to Gitesh Tic-Tac-Toe Game"<<endl;
    while (!match_win && !match_draw){
        display_game(Game_board);
        cout << "Player " << player << ", enter the position where you want to place your Mark [row , column] : ";
        int row;
        int column;
        cin >> row >> column;
        if (row < 1 || row > 3 || column < 1 || column > 3 || Game_board[row -1 ][column - 1] != ' ')
        {
            cout << "Invalid input! The given input does not satisty the game rules , Try another : " << endl;
            continue;
        }
        Game_board[row - 1][column - 1] = player;
        match_win = checkWin(Game_board, player);
        match_draw = check_completet_board(Game_board);
        if (!match_win) player = (player == 'X') ? 'O' : 'X';
    }
    display_game(Game_board);
    if (match_win) cout << "Player " << player << " wins! Congratulations!" << endl;
    else cout << "It's a draw!" << endl;
}

// In this approach we are using Array
void display(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}


// This ia the function to check the game weather it is correct or not.
bool check(char arr[3][3]){
    for(int i = 0; i< 3; i++){
        for(int j = 0; j< 3; j++){
            if(arr[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

// This is the function to check weather the player win or defeat
bool Win_Or_Not(char arr[3][3], char gamer){
    for(int i = 0; i < 3 ; i++){
        if (arr[i][0] == gamer && arr[i][1] == gamer && arr[i][2] == gamer)return true;
        if (arr[0][i] == gamer && arr[1][i] == gamer && arr[2][i] == gamer)return true;
    }
    if (arr[0][0] == gamer && arr[1][1] == gamer && arr[2][2] == gamer)return true; 
    if (arr[0][2] == gamer && arr[1][1] == gamer && arr[2][0] == gamer)return true;
    return false;
}

// This is the main function which start the game.
void Tic_Tak_Toe_Game(){
    char Game_Array[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char Gamer = 'X';
    bool win = false;
    bool draw = false;
    while(!win && !draw){
        cout << "Player " << Gamer << ", enter the position where you want to place your Mark [row , column] : ";
        int rows , columns;
        cin >> rows >> columns;
        if(rows < 0 || rows >3 || columns < 0 || columns > 3 || Game_Array[rows][columns] != ' '){
            cout << "Invalid input! The given input does not satisty the game rules , Try another : " << endl;
            continue;
        }
        Game_Array[rows][columns] = Gamer;
        win = Win_Or_Not(Game_Array , Gamer);
        draw = check(Game_Array);
        if(!win) Gamer = (Gamer == 'X') ? 'O' : 'X';
        display(Game_Array);
        if(win) cout << "Player " << Gamer << " wins! Congratulations!" << endl;
    }
  
}
int main(){
    // calling the function of vecter method
    // Tic_Tak_Game();

    // Calling the main function of array method
     Tic_Tak_Toe_Game();
    return 0;
}
