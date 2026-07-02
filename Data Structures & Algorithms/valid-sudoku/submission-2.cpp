class Solution {
    vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<int> checkedRows{};
        std::unordered_set<int> checkedCols{};
        std::unordered_set<int> checkedSquares{};

        for (int row{}; row < board.size(); row++) {
            for (int col{}; col < board.size(); col++) {
                if (checkedRows.insert(row).second && !checkRow(row, board)) {
                    return false;
                }
                if (checkedCols.insert(col).second && !checkCol(col, board)) {
                    return false;
                }
                int sqIdx = (row / 3) * 3 + (col / 3);
                if (checkedSquares.insert(sqIdx).second && !checkSq(sqIdx, board)) {
                    return false;
                }
            }
        }
        return true; 
    }

    bool checkRow(int row, vector<vector<char>>& board) {
        std::unordered_set<char> values{};
        for (int col = 0; col < board.size(); col++) {
            if(board[row][col] == '.') {
                continue;
            }

            if (!values.insert(board[row][col]).second) {
                cout << board[row][col] << endl;
                return false;
            }
        }
        return true; 
    }

    bool checkCol(int col, vector<vector<char>>& board) {
        std::unordered_set<char> values{};
        for (int row = 0; row < board[col].size(); row++) {
            if(board[row][col] == '.') {
                continue;
            }
            if (!values.insert(board[row][col]).second) {
                cout << board[row][col] << endl;
                return false;
            }
        }
        return true; 
    }

    bool checkSq(int sqIdx, vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        
        if (sqIdx <= 2) {
            row = 1;
        } else if (sqIdx <= 5) {
            row = 4;
        } else {
            row = 7;
        }

        if (sqIdx == 0 || sqIdx == 3 || sqIdx == 6) {
            col = 1;              
        } else if (sqIdx == 1 || sqIdx == 4 || sqIdx == 7) {
            col = 4;
        } else {
            col = 7;
        }

        std::unordered_set<char> values{};
        for (auto& d : dirs) {
            int nr = row + d.first;
            int nc = col + d.second;
            if (board[nr][nc] == '.') {
                continue;
            }
            if (!values.insert(board[nr][nc]).second) {
                cout << board[row][col] << endl;
                return false;
            }
        }
        return true; 
    }
};
