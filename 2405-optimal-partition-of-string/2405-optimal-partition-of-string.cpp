class Solution {
public:
    int count(vector<int>&frq) {
        int s = 0;
        for(auto it : frq) {
            if(it != 0) s++;
        }
        return s;
    }
    int partitionString(string s) {
        
        int cnt = 0;

        int l = 0;
        int r = 0;

        vector<int>frq(26,0);

        while(r < s.size()) {

            frq[s[r]-'a']++;

            int size = count(frq);

            if(size < (r-l+1)) {
                cnt++;
                l = r;
                fill(frq.begin(),frq.end(),0);
            }
            else r++;

         //   cout << size << " " << cnt << endl;
        }

        int size = count(frq);

        if(size < (r-l+1)) cnt++;

        return cnt;
    }
};