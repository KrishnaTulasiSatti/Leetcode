class Solution {
public:
    string stringHash(string s, int k) {
        vector<string>sub;
        string a = "";
        for(int i = 0 ; i < s.size() ; i++) {
            if((i+1) % k == 0) {
                a+=s[i];
                sub.push_back(a);
                a = "";
            }
            else{
                a+=s[i];
            }
        }
        string finalAns = "";
    //    for(auto it : sub) cout<<it<<" ";
        for(int i = 0 ; i < sub.size() ; i++) {
            string c = sub[i];
            int sum = 0;
            for(auto it : c) {
                sum+=it-'a';
            }
            sum%=26;
            finalAns+=(sum+'a');
        }
        return finalAns;
    }
};