class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars{};
        int longest = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            while (chars.contains(s[r])) {
                // duplicate at r -> move l until no longer duplicate
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[r]);
            int currLen = r - l + 1;
            longest = max(currLen, longest);
        }
        return longest;
    }
};
