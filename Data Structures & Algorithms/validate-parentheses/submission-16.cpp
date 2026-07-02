class Solution {
public:
    bool isValid(string s) {
        map<char, char> rightToLeft {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        stack<char> st{};

        for (char c : s) {
            if (rightToLeft.count(c)) {
                if (!st.empty() && st.top() == rightToLeft.at(c)) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        } 
        return st.empty();
    }
};
