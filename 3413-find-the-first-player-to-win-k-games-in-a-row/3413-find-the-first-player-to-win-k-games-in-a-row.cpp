class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        if(k >= skills.size()) return max_element(skills.begin(),skills.end())-skills.begin();
        deque<int>q;
        for(int i = 0 ; i < skills.size() ; i++) {
            q.push_back(i);
        }
        vector<int>ans(skills.size(),0);
        int prev = 0;
        while(true) {
            int f = q.front();
            q.pop_front();
            int s = q.front();
            q.pop_front();
            if(skills[f] > skills[s]) {
                if(prev != f) {
                    ans[prev] = 0;
                    prev = f;
                }
                ans[f]++;
                if(ans[f] == k) return f;
                q.push_front(f);
                q.push_back(s);
            }
            else{
                if(prev != s) {
                    ans[prev] = 0;
                    prev = s;
                }
                ans[s]++;
                if(ans[s] == k) return s;
                q.push_front(s);
                q.push_back(f);
            }


        }
        return -1;


    }
};