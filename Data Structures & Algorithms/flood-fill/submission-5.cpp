class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_color = image[sr][sc];
        if (color == og_color) return image;
        
        queue<pair<int, int>> q;
        q.emplace(sr, sc);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //below, above, right, left
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int row = curr.first, col = curr.second;
            image[row][col] = color;                       
            q.pop();

            for (auto &d: directions) {
                int new_row = row + d[0];
                int new_col = col + d[1];
                if(new_row >= 0 && new_row < image.size() && new_col >= 0 && new_col < image[0].size() && image[new_row][new_col] == og_color) {
                    q.emplace(new_row, new_col);                       
                }
            }
        }

        for (const auto& row : image) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n"; 
        }

        return image;
    }

    bool contains_pair(vector<pair<int, int>>& points, int idx1, int idx2) {
        auto it = std::find(points.begin(), points.end(), std::make_pair(idx1, idx2));
        return it != points.end();      
    }

};