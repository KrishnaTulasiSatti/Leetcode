class Solution {
public:
    int maxScore(string s) {
        int cnt = 0;

        vector<int>zeroes(s.size(),0);
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '0') cnt++;
            zeroes[i] = cnt;
        }

        vector<int>ones(s.size(),0);

        cnt = 0;
    
        int maxi = 0;

        for(int i = s.size()-1 ; i >= 0 ; i--) {
            if(s[i] == '1') cnt++;
            ones[i] = cnt;
        }

       

        for(int i = 0 ; i < s.size()-1; i++) {
            maxi = max(maxi,zeroes[i]+ones[i+1]);
        }


        return maxi;

        
    }
};