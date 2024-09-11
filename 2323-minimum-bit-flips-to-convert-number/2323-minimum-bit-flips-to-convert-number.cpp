class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int i = 0;
        while(start || goal) {
            int a = start & 1;
            int b = goal & 1;
            if(a != b) cnt++;
            start/=2;
            goal/=2;
            
        }
        return cnt;
    }
};