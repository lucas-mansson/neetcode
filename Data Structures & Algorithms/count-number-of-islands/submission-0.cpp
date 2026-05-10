class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    islands++;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);

                    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // below, above, right, left
                    while(!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        for (auto &d : directions) {
                            int new_row = curr.first + d.first, new_col = curr.second + d.second;
                            if(new_row >= 0 && new_row < grid.size() 
                            && new_col >= 0 && new_col < grid[0].size() 
                            && grid[new_row][new_col] == '1') {
                                grid[new_row][new_col] = '0';
                                q.emplace(new_row, new_col);
                            }
                        }
                        
                    }
                }
            }
        }
        return islands;
    }
};
