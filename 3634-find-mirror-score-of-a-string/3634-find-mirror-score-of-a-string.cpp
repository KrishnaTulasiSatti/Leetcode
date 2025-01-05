class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>>mat(26);
        
        long long score = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            int a = abs(25-(s[i]-'a'));
            char ch = a+'a';
            if(mat[a].size() != 0) {
                int s = mat[a].size();
                int j = mat[a][s-1];
                mat[a].pop_back();
                score+=(i-j);
            }
            else{
              mat[s[i]-'a'].push_back(i);
            }
            
        }
        return score;
    }
};