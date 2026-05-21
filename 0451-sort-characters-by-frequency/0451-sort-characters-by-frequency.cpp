class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int>m;

        for(auto& it : s) {
            m[it]++;
        }

        vector<pair<int,int>>v;

        for(auto& it : m) {
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),greater<>());

        string res = "";

        for(auto& it : v) {
            for(int i = 0 ; i < it.first ; i++) {
                res += it.second;
            }
        }
        

        return res;
    }
};