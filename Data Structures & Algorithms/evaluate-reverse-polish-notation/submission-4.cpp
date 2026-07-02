class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 

        for (string& s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();          
                int a = st.top(); st.pop();          

                st.push(compute(a, b, s));
                continue;
            } 
            st.push(stoi(s));
        }

        return st.top();
    }

    int compute(int a, int b, string op) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return a - b;
        } else if (op == "*") {
            return a * b;
        } else if (op == "/") {
            return a / b;
        }
        throw invalid_argument("bad arguments");
    }
};
