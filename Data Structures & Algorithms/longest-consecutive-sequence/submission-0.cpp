class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int longestSeq{};

        for (int i{}; i < nums.size(); i++) {
            int nbr = nums[i];
            // if nbr - 1 doesnt exist in the set, then
            // we have the start of a sequence
            if (!s.contains(nbr - 1)) {
                int currSeq{};
                int j = 0;
                while(s.contains(nbr + j)) {
                    currSeq++;
                    j++;
                }
                longestSeq = std::max(longestSeq, currSeq);
            }
        } 
        return longestSeq;
    }
};
