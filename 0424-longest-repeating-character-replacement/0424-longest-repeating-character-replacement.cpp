class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0;
        int r = 0;

        int maxi = 0;

        unordered_map<char,int>m;

        while(r < s.size()) {

            m[s[r]]++;
            
            int curr_max = 0;
            for(auto& it : m) curr_max = max(curr_max,it.second);

            int cnt = (r-l+1)-(curr_max);

            while(cnt > k && l < s.size()) {
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                int curr_max = 0;
                for(auto& it : m) curr_max = max(curr_max,it.second);
                l++;
                cnt = (r-l+1)-(curr_max);
            }

            maxi = max(maxi,r-l+1);
            r++;
        }


        return maxi;
    }
};