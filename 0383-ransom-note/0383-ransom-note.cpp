class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> alpha;
        for(auto m : magazine){
            alpha[m]++;
        }

        for(auto r : ransomNote){
            if(!alpha[r]) return false;
            alpha[r]--;
        }

        return true;
    }
};