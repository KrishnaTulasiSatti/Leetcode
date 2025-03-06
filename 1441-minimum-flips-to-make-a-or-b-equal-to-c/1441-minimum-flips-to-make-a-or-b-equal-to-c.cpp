class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0 ; i < 32 ; i++) {
            int x = a & 1;
            int y = b & 1;
            int z = c & 1;
            if(x+y == 0 && z == 1) cnt++;
            else if(x+y == 1 && z == 0) cnt++;
            else if(x+y == 2 && z == 0) cnt+=2;
            a/=2;
            b/=2;
            c/=2;
        }
        return cnt;
    }
};