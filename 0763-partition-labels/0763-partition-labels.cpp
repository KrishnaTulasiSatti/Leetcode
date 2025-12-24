class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>frq(26,-1);

        for(int i = 0 ; i < s.size() ; i++) {
            frq[s[i]-'a'] = i;
        }


        int end = frq[s[0]-'a'];
      //  cout << end;

        vector<int>res;

        int j = 0;

        for(int i = 1 ; i < s.size() ; i++) {

            if(i > end) {
                res.push_back(end-j+1);
                end = frq[s[i]-'a'];
                j = i;
            }
            else end = max(end,frq[s[i]-'a']);
        }

        res.push_back(s.size()-j);

        return res;
    }
};