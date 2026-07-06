class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low(0);
        int high(heights.size() - 1);
        int maxArea;

        while (low != high) {
            int shortest = min(heights[low], heights[high]);
            int area = (high - low) * shortest;
            
            maxArea = max(area, maxArea); 
        
            cout << "Area: " << area << ". high - low: " << high << "-" << low << ". Shortest: " << shortest; 

            if (shortest == heights[low]) {
                low++;
            } else {
                high--;
            }
        }

        return maxArea; 
    }
};
