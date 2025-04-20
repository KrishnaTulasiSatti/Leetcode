class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;

        for(auto it : answers) {
            m[it]++;
        }

        int cnt = 0;

        for(auto it : m) {
            int a = it.first;
            int b = it.second;
            
            if(a > b) cnt += (a+1);
            else {
                if(b % (a+1)) {
                    cnt += ((b/(a+1))+1)*(a+1);
                }
                else {
                    cnt += ((b/(a+1))*(a+1));
                }
            }
            
        }
        return cnt;
    }
};