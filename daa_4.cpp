#include <assert.h>
#include <iostream>

using namespace std;

bool board[20][20];
int n;

void disp_board()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
}

bool row_nonempty(int row) {
    for (int j = 0; j < n; j++)
        if (board[row][j]) return true;

    return false;
}

bool isSafe(int row, int col) {
    for (int i = 0; i < n; i++)
        if (board[i][col]) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++)
        if (board[i][j]) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;
        
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveNQueens(int row) {
    if (row == n) return true;
    if (row_nonempty(row)) return solveNQueens(row + 1); // skip row

    for (int col = 0; col < n; col++) {
        if (!isSafe(row, col)) continue;
        board[row][col] = true;
        if (solveNQueens(row + 1)) return true;
        board[row][col] = false;
    }

    return false;
}

int main() {
    int r, c;

    cout << "Enter value of N: ";
    cin >> n;
    assert(1 <= n && n <= 20);

    cout << "Enter row and column of first Queen (0-based): ";
    cin >> r >> c;
    assert(0 <= r && r <= n);
    assert(0 <= c && c <= n);
    board[r][c] = true;

    assert(solveNQueens(0) && "No solution exists for this first Queen position.\n");

    cout << "\nFinal N-Queens Matrix:\n";
    disp_board();

    return 0;
}
