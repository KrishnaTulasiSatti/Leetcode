class Solution {
public:
    string clearStars(string s) {

        vector<int>vis(s.size(),1);

        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;

        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '*'){
                if(!pq.empty()) {
                    auto top = pq.top();
                    vis[-1*top.second] = 0;
                    pq.pop();
                }
            }
            else {
                pq.push({s[i],-1*i}); // If characters equal they will be arranged in max index order
            }
        }

        string res = "";
        for(int i = 0 ; i < s.size() ; i++) {
            if(vis[i] == 1 && s[i] != '*') res += s[i];
        }
        return res;
    }
};