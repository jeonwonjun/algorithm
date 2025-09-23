class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";
        for (int i=0; i<s.size(); i++) {
            if (65 <= s[i] && s[i] <= 90)
                tmp += (s[i] + 32);
            else if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
                tmp += s[i];

        }

        if (tmp.size() <= 1)
            return true;

        int i=0;
        int mid = tmp.size()/2;
        while (i < mid) {
            if (tmp[i] != tmp[tmp.size() - 1 - i])
                return false;
            i++;
        }

        return true;
    }
};