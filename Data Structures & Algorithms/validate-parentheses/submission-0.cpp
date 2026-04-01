class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char &ch: s) {
            if(ch == '(' || ch == '[' || ch == '{' || st.empty()) {
                st.push(ch);
                continue;
            }

            else if(ch == ')') {
                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if(ch == ']') {
                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if(ch == '}') {
                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
