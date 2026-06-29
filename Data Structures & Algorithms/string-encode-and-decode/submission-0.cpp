class Solution {
public:
    char delimiter{'#'};

    string encode(vector<string>& strs) {
        std::string res{""};

        for (auto& str: strs) {
            std::string len = std::to_string(str.length());
            res += len + delimiter + str;
        }
        
        return res;
    }

    vector<string> decode(string s) {
        size_t i{0};
        std::vector<std::string> res{};
        while (i < s.length()) {
            size_t j{i};

            // parse word length
            while (s[j] != delimiter && j < s.length()) {
                j++;
            }
            int wordLen = std::stoi(s.substr(i, i + j));

            j++; // skip delimiter char

            // get actual word
            std::string word = s.substr(j, wordLen);
            res.push_back(word); 

            // go to next word
            i = j + wordLen;
        }
        return res;
    }
};
