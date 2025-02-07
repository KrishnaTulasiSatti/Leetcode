class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       
        unordered_map<int,int>m;
        multiset<int>s; 
        vector<int>res;  
        set<int>st;   
        for(int i = 0 ; i < queries.size() ; i++) {
             int b = queries[i][0];
             int c = queries[i][1];
            // cout<<m[b]<<" ";
            if(m[b] > 0) {
                s.erase(s.find(m[b]));
                if(s.find(m[b]) == s.end()) st.erase(m[b]);
            }
            m[b] = c;
            s.insert(c);
            st.insert(c);
            res.push_back(st.size());
        }
        return res;
    }
};