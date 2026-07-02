class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> cols;
        std::map<std::pair<int, int>, std::unordered_set<char>> squares;

        for (int row{}; row < board.size(); row++) {
            for (int col{}; col < board.size(); col++) {
                char val = board[row][col];
                if (val == '.') {
                    continue;
                }

                if (!rows.contains(row)) {
                    rows.insert({row, {val}});
                } else {
                    if (!rows.at(row).insert(val).second) {
                        return false;
                    }
                }

                if (!cols.contains(col)) {
                    cols.insert({col, {val}});
                } else {
                    if (!cols.at(col).insert(val).second) {
                        return false;
                    }
                }

                std::pair<int, int> sqKey = {row / 3, col / 3};
                if (!squares.contains(sqKey)) {
                    squares.insert({sqKey, {val}});
                } else {
                    if (!squares.at(sqKey).insert(val).second) {
                        return false;
                    }
                }
            }
        }
        return true; 
    }
};
