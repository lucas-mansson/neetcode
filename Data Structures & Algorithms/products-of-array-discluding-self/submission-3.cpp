class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        std::vector<int> prefixes(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            prefix *= nums[i];
            prefixes[i + 1] = prefix; 
        }

        std::vector<int> suffixes(nums.size(), 1);
        int suffix = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
                suffix *= nums[i];
                suffixes[i - 1] = suffix;
        }

        std::vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            res[i] = prefixes[i] * suffixes[i];
        }

        return res;
    }
};
