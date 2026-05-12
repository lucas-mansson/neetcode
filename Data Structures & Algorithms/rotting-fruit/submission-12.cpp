class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        const int FRESH = 1;
        const int ROTTEN = 2;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;

        queue<pair<int, int>> rotten;
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                }
                if(grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        int minutes = 0;
        while(!rotten.empty() && fresh > 0) {
            int size = rotten.size();
            minutes++;
            for (int size = rotten.size(); size > 0; size--) {
                auto curr = rotten.front(); rotten.pop();

                for (auto d : directions) {
                    int nr = curr.first + d[0];
                    int nc = curr.second + d[1];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == FRESH) {
                        rotten.push({nr, nc});
                        grid[nr][nc] = ROTTEN;
                        fresh--;
                    } 
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
