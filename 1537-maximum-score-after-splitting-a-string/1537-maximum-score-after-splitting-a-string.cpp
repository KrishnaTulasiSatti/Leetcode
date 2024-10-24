class Solution {
public:
    int maxScore(string s) {
        int zeroes = 0;
        int ones = 0;
        for(auto it : s) {
            if(it == '1') ones++;
            else zeroes++;
        }
        int maxi = 0;
        int z = 0;
        int o = 0;
        cout<<zeroes<<" "<<ones<<endl;
        for(int i = 0 ; i < s.size()-1 ; i++) {
            if(s[i] == '0') z++;
            else o++;
            
            maxi = max(maxi,z+(ones-o));

        }
        return maxi;
    }
};