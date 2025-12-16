class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        
        int cnt = 0;

        int i = 1;

        while(memory1 >= i || memory2 >= i) {

            if(memory1 >= memory2) memory1 -= i;
            else memory2 -= i;

            i++;
            cnt++;

        }

        return {cnt+1,memory1,memory2};
    }
};