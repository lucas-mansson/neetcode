class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> visited;
        queue<pair<int, int>> q;

        q.emplace(sr, sc);
        visited.push_back(make_pair(sr, sc));
        int og_color = image[sr][sc];
        cout << og_color;
        if (color == og_color) return image;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            image[curr.first][curr.second] = color;
            q.pop();
          
            // Above
            int i1 = curr.first-1;
            int i2 = curr.second;
            if(i1 >= 0 && image[i1][i2] == og_color) {  
                if(!contains_pair(visited, i1, i2)) {
                    q.emplace(i1, i2);
                }
            }
            // Below
            i1 = curr.first + 1;
            i2 = curr.second;
            if(i1 <= image.size() - 1 && image[i1][i2] == og_color) {  
                if(!contains_pair(visited, i1, i2)) {
                    q.emplace(i1, i2);
                }
            }
            // Left
            i1 = curr.first;
            i2 = curr.second - 1;
            if(i2 >= 0 && image[i1][i2] == og_color) {   
                if(!contains_pair(visited, i1, i2)) {
                    q.emplace(i1, i2);
                }
            }
            // Right
            i1 = curr.first;
            i2 = curr.second + 1;
            if(i2 <= image[0].size() - 1 && image[i1][i2] == og_color) {  
                if(!contains_pair(visited, i1, i2)) {
                    q.emplace(i1, i2);
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