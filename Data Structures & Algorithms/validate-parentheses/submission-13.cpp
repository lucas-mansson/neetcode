class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) {
            return true;
        }
        if (s.size() % 2 != 0) {
            return false;
        }
        map<char, char> rightToLeft {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        stack<char> st{};

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (st.size() == 0) {
                    return false;
                }
                char left = st.top(); 
                st.pop();
                if(left != rightToLeft.at(c)) {
                    return false;
                }
            }
        } 
        return st.size() == 0;
    }
};
