class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        int ans = (start ^ goal);
        for(int i = 0 ; i < 32 ; i++) {
            if(ans % 2) res++;
            ans = ans >> 1;
        }
        return res;
    }
};