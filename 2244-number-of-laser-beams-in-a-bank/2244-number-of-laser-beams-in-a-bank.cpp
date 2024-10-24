class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0;
        for(int i = 0 ; i < bank.size()-1 ; i++) {
            int prev = 0;
            int curr = 0;
            string str1 = bank[i];
            string str2 = bank[i+1];
            
            for(auto it : str1) {
                if(it == '1') prev++;
            }
            for(auto it : str2) {
                if(it == '1') curr++;
            }
            if(curr == 0) bank[i+1] = bank[i];
            cnt+=(prev*curr);
            

        }
        return cnt;
    }
};