#include <iostream>
#include <vector>
using namespace std;

void resetBoard(vector<vector<char>> &board) {
    board.clear();
    for (int i = 0; i < 8; i++) {
        vector<char> row(8);
        for (int j = 0; j < 8; j++)
            row[j] = '.';
        board.push_back(row);
    }
}

bool check(int row, int col, vector<vector<char>> &board) {
    //assumes a queen hasnt been added to row, col
    for (int i = 0; i < 8; i++) {
        if (board[row][i] == 'Q') return false;
        if (board[i][col] == 'Q') return false;
    }
    int i, j;
    i = row, j = col;
    while (i >= 0 and i < 8 and j >= 0 and j < 8) {
        if (board[i][j] == 'Q') return false;
        i--; j--;
    }
    i = row, j = col;
    while (i >= 0 and i < 8 and j >= 0 and j < 8) {
        if (board[i][j] == 'Q') return false;
        i--; j++;
    }
    i = row, j = col;
    while (i >= 0 and i < 8 and j >= 0 and j < 8) {
        if (board[i][j] == 'Q') return false;
        i++; j--;
    }
    i = row, j = col;
    while (i >= 0 and i < 8 and j >= 0 and j < 8) {
        if (board[i][j] == 'Q') return false;
        i++; j++;
    }
    return true;
}

int moves(vector<vector<char>> &board, vector<vector<char>> &toCheck) {
    int out = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (toCheck[i][j] == 'Q' and board[i][j] != 'Q') out++;
    return out;
}

void movesTo8Queens(int &ans, int row, vector<vector<char>> &board, vector<vector<char>> &toCheck) {
    if (row == 8) {
        int m = moves(board, toCheck);
        if (m < ans) ans = m;
        return;
    }
    
    for (int i = 0; i < 8; i++) {
        if (check(row,i,board)) {
            board[row][i] = 'Q';
            movesTo8Queens(ans, row+1, board, toCheck);
            board[row][i] = '.';
        }
    }
}

int main() {
    vector<vector<char>> board;
    vector<vector<char>> toCheck;
    vector<int> pos(8);
    resetBoard(board);

    int c = 0;
    while (cin >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5] >> pos[6] >> pos[7]) {
        c++;
        cout << "Case " << c << ": ";
        resetBoard(toCheck);
        for (int i = 0; i < 8; i++)
            toCheck[pos[i]-1][i] = 'Q';
        int ans = 8;
        movesTo8Queens(ans, 0, board, toCheck);
        cout << ans << endl;
    }
}
