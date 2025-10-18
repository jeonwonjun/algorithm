class Solution {
public:
    int longestPalindrome(string s) {
        
        int answer = 0;

        // 1. plus char at hash
        unordered_map<char, int> alpha;
        for(char c : s){
            alpha[c]++;
        }

        // 2. plus all even hash
        for(auto pair : alpha){
            if(pair.second % 2 == 0)
                answer += pair.second;
            else{
                answer += pair.second - 1;
            }
        }

        // 3. exist odd
        if (odd_max > 0)
            answer += 1;

        return answer;
    }
};