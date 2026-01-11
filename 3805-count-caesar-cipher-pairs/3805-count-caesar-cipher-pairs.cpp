class Solution {
public:

    string convert(string& s) {

        int cnt = ('z'-s[0])+1;
       // cout << cnt << endl;

        string ans = "";

        for(int i = 0 ; i < s.size() ; i++) {
            char ch = ((s[i]+cnt) % 26) + 'a';
            ans += ch;
        }

      //  cout << ans << endl;
        return ans;
    }
    long long countPairs(vector<string>& words) {

        long long cnt = 0;

        unordered_map<string,long long>m;

        for(int i = 0 ; i < words.size() ; i++) {

            string s = convert(words[i]);
            m[s]++;

        }

        for(auto it : m) {
            cnt += (it.second)*(it.second-1)/2;
        }

        return cnt;
    }
};