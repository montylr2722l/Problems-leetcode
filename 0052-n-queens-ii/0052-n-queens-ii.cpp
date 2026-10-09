
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    int solve(vector<vector<char>>& board, int row, int n) {
        if (row == n) {
            return 1;
        }

        int count = 0;

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';

                count += solve(board, row + 1, n);

                board[row][col] = '.';
            }
        }

        return count;
    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        return solve(board, 0, n);
    }
};
