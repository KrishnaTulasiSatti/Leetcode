class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>m;
        for(int i = 0 ; i < s.size() ; i++) {
            m[s[i]]++;
        }
        int len = 0;
        for(auto it : m) {
            int occ = it.second;
           // cout<<it.first<<" "<<it.second<<" ";
            if(occ < 3) len+=occ;
            else{
                while(occ >= 3) {
                    occ-=2;
                }
                len+=occ;
            }
           // cout<<len<<endl;
        }
        return len;
    }
};