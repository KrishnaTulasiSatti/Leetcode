class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

       

        vector<int>count;

        for(int i = 0 ; i < bank.size() ; i++) {

            string s = bank[i];

            int cnt = 0;

            for(auto it : s) {
                if(it == '1') cnt++;
            }
            
            if(cnt == 0) continue;

            count.push_back(cnt);
        }

        int total = 0;

        if(count.size() == 0) return 0;

        for(int i = 0 ; i < count.size()-1 ; i++) {
            total += (count[i]*count[i+1]);
        }

        return total;
    }
};