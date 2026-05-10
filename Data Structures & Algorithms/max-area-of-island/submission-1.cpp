class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int curr_area = 1;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);

                    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    while(!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        for (auto d : dirs) {
                            int new_row = curr.first + d.first;
                            int new_col = curr.second + d.second;

                            if (new_row >= 0 && new_row < grid.size()
                            && new_col >= 0 && new_col < grid[0].size()
                            && grid[new_row][new_col] == 1) {
                                curr_area++;
                                grid[new_row][new_col] = 0;
                                q.emplace(new_row, new_col);
                            } 
                        }
                    }
                    if(curr_area > max_area) {
                        max_area = curr_area;
                    }
                }
            }
        }
        return max_area;
    }
};
