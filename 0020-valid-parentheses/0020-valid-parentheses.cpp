class Solution {
public:
    bool isValid(string s) {
        // input max size is 10000, so time complexity less than O(n^2)
        int n = s.size();
        vector<char> st(n);
        int top = -1; // s.empty();

        for (char c : s) {
            switch(c) {
                case '(': case '[': case '{':
                    st[++top] = c;
                    break;
                case ')':
                    if (top < 0 || st[top] != '(') return false;
                    top--;
                    break;
                case ']':
                    if (top < 0 || st[top] != '[') return false;
                    top--;
                    break;
                case '}':
                    if (top < 0 || st[top] != '{') return false;
                    top--;
                    break;
            }
        }

        return top == -1;
    }
};