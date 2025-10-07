#include <iostream>
#include <string>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
char board[ROWS][COLS];

// Player names and markers
string player1_name = "Player 1";
string player2_name = "Player 2";
char player1_marker = 'X';
char player2_marker = 'O';

// Initialize board
void initializeBoard() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            board[i][j] = ' ';
}

// Draw board
void drawBoard() {
    system("clear"); // clear terminal
    cout << "\n";
    for(int i=0;i<ROWS;i++){
        cout << "|";
        for(int j=0;j<COLS;j++){
            cout << board[i][j] << "|";
        }
        cout << "\n";
    }
    for(int j=0;j<COLS;j++) cout << "==";
    cout << "=\n";
    for(int j=1;j<=COLS;j++) cout << " " << j;
    cout << "\n\n";
}

// Place marker in column
bool placeMarker(int col, char marker) {
    if(col < 0 || col >= COLS) return false;
    for(int i=ROWS-1;i>=0;i--){
        if(board[i][col] == ' '){
            board[i][col] = marker;
            return true;
        }
    }
    return false; // column full
}

// Check horizontal, vertical, diagonal win
bool checkWinner(char marker) {
    // Horizontal
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS-3;j++){
            if(board[i][j]==marker && board[i][j+1]==marker &&
               board[i][j+2]==marker && board[i][j+3]==marker)
               return true;
        }
    }
    // Vertical
    for(int i=0;i<ROWS-3;i++){
        for(int j=0;j<COLS;j++){
            if(board[i][j]==marker && board[i+1][j]==marker &&
               board[i+2][j]==marker && board[i+3][j]==marker)
               return true;
        }
    }
    // Diagonal /
    for(int i=3;i<ROWS;i++){
        for(int j=0;j<COLS-3;j++){
            if(board[i][j]==marker && board[i-1][j+1]==marker &&
               board[i-2][j+2]==marker && board[i-3][j+3]==marker)
               return true;
        }
    }
    // Diagonal 
    for(int i=0;i<ROWS-3;i++){
        for(int j=0;j<COLS-3;j++){
            if(board[i][j]==marker && board[i+1][j+1]==marker &&
               board[i+2][j+2]==marker && board[i+3][j+3]==marker)
               return true;
        }
    }
    return false;
}

// Check draw
bool isDraw() {
    for(int j=0;j<COLS;j++)
        if(board[0][j] == ' ') return false;
    return true;
}

// Main game loop
void game() {
    cin.ignore(); // Clear buffer
    string name1, name2;
    cout << "Enter Player 1 name (or press Enter to keep default): ";
    getline(cin, name1);
    if(!name1.empty()) player1_name = name1;

    cout << "Enter Player 2 name (or press Enter to keep default): ";
    getline(cin, name2);
    if(!name2.empty()) player2_name = name2;

    initializeBoard();
    drawBoard();

    int turn = 0; // 0=player1, 1=player2
    while(true){
        string current_name = (turn==0)? player1_name : player2_name;
        char current_marker = (turn==0)? player1_marker : player2_marker;

        int col;
        cout << current_name << " (" << current_marker << "), choose column (1-" << COLS << "): ";
        cin >> col;
        col--; // convert to 0-based index

        if(!placeMarker(col, current_marker)){
            cout << "Invalid move! Try again.\n";
            continue;
        }

        drawBoard();

        if(checkWinner(current_marker)){
            cout << "🎉 " << current_name << " wins the game!\n";
            break;
        }

        if(isDraw()){
            cout << "It's a draw!\n";
            break;
        }

        turn = 1 - turn; // swap player
    }
}

// Main function
int main(){
    game();
    return 0;
}
