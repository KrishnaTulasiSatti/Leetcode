class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>m;
        for(auto it : changed) {
            m[it]++;
        }

        sort(changed.begin(),changed.end());
        vector<int>res;

        

        for(int i = 0 ; i < changed.size() ; i++) {
            int n = changed[i];
            int d = n*2;
            if(m[n] > 0) {
                m[n]--;

                if(m[n] == 0) m.erase(n);

                if(m[d] > 0) {
                    m[d]--;
                    res.push_back(n);
                }

                if(m[d] == 0) m.erase(d);
            }
        }
        
        int size = res.size();
        if(size*2 == changed.size()) return res;
        return {};
    }
};