class Solution {
public:
    bool isValid(string s) {
        // input max size is 10000, so time complexity less than O(n^2)
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty())
                    return false;
                char k = st.top();
                if (k == '(' && s[i] == ')')
                    st.pop();
                else if (k == '[' && s[i] == ']')
                    st.pop();
                else if (k == '{' && s[i] == '}')
                    st.pop();
                else
                    return false;
            }
        }

        if (!st.empty())
            return false;

        return true;
    }
};