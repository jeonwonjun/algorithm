class Solution {
public:
    bool isAnagram(string s, string t) {
        // s valuse push in to hashTable
        unordered_map<char, int> anagram;
        
        for(char c : s) {
            anagram[c]++;
        }

        for(char c : t) {
            anagram[c]--;
        }

        for (const auto& [key, value] : anagram) {
            if (value != 0) {
                return false; // 하나라도 0이 아니면 false
            }
    }
    return true;
        
    }
};