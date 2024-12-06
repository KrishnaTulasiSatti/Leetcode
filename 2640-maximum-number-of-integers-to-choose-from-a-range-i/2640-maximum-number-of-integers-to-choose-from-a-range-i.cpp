class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int>frq(n+1,0);
        for(int i = 0 ; i < banned.size() ; i++) {
            if(banned[i] > n) continue;
            frq[banned[i]] = -1;
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(frq[i] == 0 && sum+i <= maxSum) {
                cout<<i<<" ";
                sum+=i;
                cnt+=1;
            }
        }
        return cnt;
    }
};