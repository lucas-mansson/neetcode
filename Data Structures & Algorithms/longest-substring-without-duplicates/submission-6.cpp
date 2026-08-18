class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return s.length();
        }

        int longest = 1;
        int l = 0;
        int r = 1;
        unordered_set<char> chars{};
        chars.insert(s[l]);

        while (r < s.length()) {
            while (chars.contains(s[r])) {
                // duplicate at r -> move l until no longer duplicate
                chars.erase(s[l]);
                l++;
            }
            int currLen = r - l + 1;
            longest = max(currLen, longest);
            chars.insert(s[r]);
            r++;
        }
        return longest;
    }
};
