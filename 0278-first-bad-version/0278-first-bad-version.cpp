// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int i = n;
        bool k = isBadVersion(i);
        while(k != false){
            k = isBadVersion(--i);
        }

        return i+1;
    }
};