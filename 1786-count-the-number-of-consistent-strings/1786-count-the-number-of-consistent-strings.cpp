class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>m;
        for(auto it : allowed) m[it]++;
        int cnt = 0;
        for(int i = 0 ; i < words.size() ; i++) {
            int flag = 1;
            for(int j = 0 ; j < words[i].size() ; j++) {
               if(m.find(words[i][j]) == m.end()) {
                flag = 0;
                break;
               }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};