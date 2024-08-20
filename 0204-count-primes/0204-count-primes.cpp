class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        vector<int>vis(n,-1);
        vis[0] = 0;
        vis[1] = 0;
        for(int i = 2 ; i*i < n ; i++) {
            if(vis[i] == -1) {
                for(int j = i*i ; j < n; j+=i) {
                    vis[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(vis[i] == -1) cnt++;
        }
        return cnt;
    }
};