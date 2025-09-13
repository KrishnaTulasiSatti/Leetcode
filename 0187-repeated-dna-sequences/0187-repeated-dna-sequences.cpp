class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string,int>m;

        string temp = "";

        for(int i = 0 ; i < 10 ; i++) {
            temp += s[i];
        }

       
        int l = 0;
        int r = 10;

        while(r < s.size()) {

            m[temp]++;

            temp.erase(0,1);

            temp+=s[r];

            l++;
            r++;


        }
        m[temp]++;

        vector<string>res;

        for(auto it : m) {
            if(it.second > 1) res.push_back(it.first);
        }

        return res;
    }
};