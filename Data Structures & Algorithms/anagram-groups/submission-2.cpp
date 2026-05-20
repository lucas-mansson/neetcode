class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> m;

        for (auto const& s : strs) {
            array<int, 26> arr{};
            for (char c : s) {
                arr[c - 'a']++;
            }

            auto it = m.find(arr);
            if(it != m.end()) {
                it->second.push_back(s);
            } else {
                m.insert({arr, {s}});
            }
        }
        
        vector<vector<string>> res;
        for (auto& [key, value] : m) {
            res.push_back(value);
        }
        return res;
    }
};
