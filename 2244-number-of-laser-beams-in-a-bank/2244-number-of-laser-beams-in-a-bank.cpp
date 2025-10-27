class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0;

        int i = 0;

        while(i < bank.size()) {

            string curr = bank[i];
            i++;

            if(i >= bank.size()) break;

            while(i < bank.size() && bank[i].find('1') == string::npos) i++;

            if(i >= bank.size()) break;

            string next = bank[i];

            int c1 = 0 , n1 = 0;

            for(auto it : curr) if(it == '1') c1++;
            for(auto it : next) if(it == '1') n1++;

            cnt += (c1*n1);

        }

        return cnt;
    }
};