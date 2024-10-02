class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int>m;
        for(auto it : bannedWords) m[it]++;
        int cnt = 0;
        for(auto it : message) {
            if(m[it] > 0) cnt++;
        }
        return (cnt >= 2) ? true : false;
    }
};