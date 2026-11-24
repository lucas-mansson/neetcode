class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        Brute force, O(n^2)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        */

        /* sort copy, then use that copy to find indices
           O(n log n) for sorting + O(n) for two pointer
        // first = value, second = orig index
        std::vector<std::pair<int, int>> copy;
        for (int i = 0; i < nums.size(); i++) {
            copy.push_back({nums[i], i});
        }
        // sort by first value
        std::sort(copy.begin(), copy.end());

        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int curr = copy[i].first + copy[j].first;
            if (curr == target) {
                int lowRes = std::min(copy[i].second, copy[j].second);
                int highRes = std::max(copy[i].second, copy[j].second);
                return {lowRes, highRes};
            } else if (curr < target) {
                i++;
            } else if (curr > target) {
                j--;
            } else {
                std::cout << "Invalid state" << "\n";
                return {-1};
            }
        }
        std::cout << "Invalid state" << "\n";
        return {-1};
        */

        // map nums[index]: index
        std::unordered_map<int, int> valToIdx{};

        for (int i = 0; i < nums.size(); i++) {
            valToIdx.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (valToIdx.count(diff)) {
                int otherIdx = valToIdx[diff];
                if (otherIdx == i) {
                    continue;
                }
                int lowRes = std::min(otherIdx, i);
                int highRes = std::max(otherIdx, i);
                return {lowRes, highRes};
            }
        }
        return {};
    }
};
