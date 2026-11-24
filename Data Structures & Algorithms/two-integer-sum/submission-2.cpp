class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        /*
        while (i != j) {
            int curr = nums[i] + nums[j];
            if (curr == target) {
                return {i, j};
            }
            if (curr < target) {
                i++;
                continue;

            } 
            if (curr > target) {
                j--;
                continue;
            }
            std::cout << "Invalid state" << "\n";
            return {-1};
        }
        std::cout << "Invalid state" << "\n";
        return {-1};
        */
    }
};
