class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>res;
        string ans = "";
        for(int i = 0 ; i < target.size() ; i++) {
            char c = 'a';
            while(c <= target[i]) {

                res.push_back(ans+c);
             //   cout<<ans+c<<endl;
                c++;
            }
            ans = res[res.size()-1];
           // cout<<ans<<endl;
        }
        return res;
    }
};