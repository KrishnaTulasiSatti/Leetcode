class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string>v;
        v.push_back("0");
        for(int i = 1 ; i < n ; i++) {
            string s = v[i-1];
            string r = s+"1";
            for(int j = s.size()-1 ; j >= 0 ; j--) {
                if(s[j] == '1') r+="0";
                else r+="1";
            }
            v.push_back(r);
        }
        string ans = v[n-1];
        return ans[k-1];
    }
};