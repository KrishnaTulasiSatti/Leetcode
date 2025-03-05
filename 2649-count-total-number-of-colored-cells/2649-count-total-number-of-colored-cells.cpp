class Solution {
public:
    long long coloredCells(int n) {
        long long cnt = 0;
        
        for(int i = 1 ; i < (n*2-1) ; i+=2) {
            cnt+=(2*i);
        }
        cnt+=(n*2-1);
        return cnt;

    }
};