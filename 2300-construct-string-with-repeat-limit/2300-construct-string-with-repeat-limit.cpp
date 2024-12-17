class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>m;
        for(int i = 0 ; i < s.size() ; i++) {
            m[s[i]]++;
        }
        
        priority_queue<pair<char,int>>pq;
        for(auto it : m) {
            pq.push(it);
        }
        
        string res = "";
        while(!pq.empty()) {
            auto top = pq.top();
            int a = repeatLimit;
            if(top.second <= repeatLimit) {
               while(top.second--) res+=top.first;
               pq.pop();
            }
            else {
                char ch = top.first;
                int cnt = top.second;
                while(a--) res+=top.first;
                pq.pop();
                if(!pq.empty()) {
                    char nch = pq.top().first;
                    int ncnt = pq.top().second;
                    res+=nch;
                    pq.pop();
                    if(ncnt-1 > 0) pq.push({nch,ncnt-1});                   
                    pq.push({ch,cnt-repeatLimit});

                }
            }
        }
        return res;
    }
};