#include <iostream>
#include <cctype> // for toupper()
#include <string>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
int current_player;
string player1_name = "Player 1";
string player2_name = "Player 2";

// Draw board function
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i != 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Place marker
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

// Check winner
int checkWinner() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]))
            return current_player;
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return current_player;
    }

    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]))
        return current_player;
    if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return current_player;

    return 0;
}

// Swap player and marker
void swapPlayerAndMarker() {
    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if (current_player == 1) current_player = 2;
    else current_player = 1;
}

// Main game
void game() {
    // Ask for player names (optional)
    string name1, name2;
    cout << "Enter Player 1 name (or press Enter to keep default): ";
    getline(cin, name1);
    if (!name1.empty()) player1_name = name1;

    cout << "Enter Player 2 name (or press Enter to keep default): ";
    getline(cin, name2);
    if (!name2.empty()) player2_name = name2;

    // Choose marker
    char marker;
    while (true) {
        cout << player1_name << ", choose your marker (X or O): ";
        cin >> marker;
        marker = toupper(marker); // Convert to uppercase automatically
        if (marker == 'X' || marker == 'O') {
            current_marker = marker;
            break;
        } else {
            cout << "Invalid marker! Choose X or O.\n";
        }
    }
    current_player = 1;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        string current_name = (current_player == 1) ? player1_name : player2_name;
        cout << current_name << ", enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try another.\n";
            i--;
            continue;
        }

        drawBoard();

        int winner = checkWinner();
        if (winner == 1 || winner == 2) {
            string winner_name = (winner == 1) ? player1_name : player2_name;
            cout << "🎉 " << winner_name << " wins the game!\n";
            return;
        }

        swapPlayerAndMarker();
    }

    cout << "It's a draw!\n";
}

// Main function
int main() {
    cin.ignore(); // Clear input buffer for getline
    game();
}
