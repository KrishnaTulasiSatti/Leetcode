class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int>m;
        
        for(int i = 0 ; i < dominoes.size() ; i++) {
            sort(dominoes[i].begin(),dominoes[i].end());
            m[dominoes[i]] = m[dominoes[i]]+1;
        }

        int cnt = 0;

        for(auto it : m) {
            cnt += (it.second*(it.second-1)/2);
        }

        return cnt;
    }
};