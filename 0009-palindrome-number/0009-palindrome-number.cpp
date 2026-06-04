class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string stringX = to_string(x);
        for (int i = 0; i < stringX.length() / 2; i++) {
            if (stringX[i] != stringX[stringX.length() - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};