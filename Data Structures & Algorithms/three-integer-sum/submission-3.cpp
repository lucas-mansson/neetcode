class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets{};

        sort(nums.begin(), nums.end());
        for(auto& num : nums) {
            cout << num << endl;
        }

        for (int i{}; i < nums.size() - 2; i++) {
            const int target(-nums[i]);

            int low(i + 1);
            int high(nums.size() - 1);
            
            while(low != high) {
                int curr(nums[low] + nums[high]);
                if (curr == target) {
                    vector<int> triplet = {nums[i], nums[low], nums[high]};
                    if (find(triplets.begin(), triplets.end(), triplet) == triplets.end()) {
                        triplets.push_back(triplet);
                    } 
                    low++;
                } else if(curr < target) {
                    low++;
                } else {
                    high--; 
                }
            }
        }

        return triplets;
    }
};
