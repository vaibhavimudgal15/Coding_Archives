class Solution {
private:
    const int N = 9; 

    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int x = 0; x < N; x++) {
            if (x != col && board[row][x] == val) return false; // Row check
            if (x != row && board[x][col] == val) return false; // Column check
        }

        //check 3 X 3 subgrid
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int r = startRow + i, c = startCol + j;
                if ((r != row || c != col) && board[r][c] == val) return false;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    char current = board[i][j];
                    if (!isSafe(i, j, board, current)) return false;
                }
            }
        }
        return true;
    }
};