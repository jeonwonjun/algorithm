class Solution {
public:
    bool isAnagram(string s, string t) {
        // s valuse push in to hashTable
        vector<int> alpha(26, 0);
        if (s.size() != t.size())
            return false;

        for (int i=0; i<s.size(); i++) {
            alpha[s[i] - 'a']++;
            alpha[t[i] - 'a']--;
        }

        for (int i=0; i<26; i++) {
            if (alpha[i] != 0)
                return false;
        }
    return true;
        
    }
};