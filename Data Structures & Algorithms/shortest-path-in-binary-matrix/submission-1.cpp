class Solution {
public:
    // bottom left, left, top left, top, top right, right, bottom right, bottom
    int directions[8][2] = {{1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1) return -1;

        map<pair<int, int>, int> distances; // distance from 0, 0 to each node
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;

        q.emplace(0, 0);
        distances[{0, 0}] = 1;
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            if (curr.first == rows - 1 && curr.second == cols - 1) {
                return distances.at(curr);
            }
            //cout << curr.first << ", " << curr.second << "\n";
            for (auto& d : directions) {
                int nr = curr.first + d[0];
                int nc = curr.second + d[1];

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0) {
                    if(!visited.contains({nr, nc})) {
                        q.push({nr, nc});
                        visited.insert({nr, nc});
                        distances[{nr, nc}] = distances[curr] + 1;
                    }
                }
            }
        }
        return -1;
    }
};