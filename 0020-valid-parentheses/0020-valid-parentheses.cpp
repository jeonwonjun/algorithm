class Solution {
public:
    bool isValid(string s) {
        // input max size is 10000, so time complexity less than O(n^2)
        stack<char> st;
        unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char k : s) {
            if (k == '(' || k == '[' || k == '{')
                st.push(k);
            else {
                if (st.empty() || st.top() != match[k])
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};