class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>m;
        for(auto it : bulbs) {
            m[it]++;
        }

        vector<int>res;

        for(auto it : m) {
            if(it.second % 2) res.push_back(it.first);
        }

        return res;
    }
};