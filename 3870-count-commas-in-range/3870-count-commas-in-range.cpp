class Solution {
public:
    int countCommas(int n) {
        
        if(n < 1000) return 0;

        return abs(1000-n)+1;
    }
};