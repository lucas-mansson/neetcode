class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low(0);
        int high(nums.size() - 1);

        while (low <= high) {
            int m = low + ((high - low) / 2);

            int curr = nums[m];

            if (curr == target) {
                return m;
            }

            if (curr < target) {
                low = m + 1;
            } else {
                high = m - 1; 
            }
        }

        return -1;
    }
};
