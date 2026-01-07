class Solution {
public:

    vector<vector<long long>>dp;

    long long fun(vector<int>& v1, vector<int>& v2,int i,int j) {

        if(j >= v1.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long pick1 = 0,pick2 = 0;

        if(i == 0) {
            pick1 = v1[j] + fun(v1,v2,0,j+1);
            pick2 = v1[j] + fun(v1,v2,1,j+2);
        }

        if(i == 1) {
            pick1 = v2[j] + fun(v1,v2,1,j+1);
            pick2 = v2[j] + fun(v1,v2,0,j+2);
        }

        return dp[i][j] = max(pick1,pick2);

    }
    long long maxEnergyBoost(vector<int>& v1, vector<int>& v2) {
        
        dp.resize(2,vector<long long>(v1.size(),-1));

        long long ans1 = fun(v1,v2,0,0);

        // dp.resize(2,vector<long long>(v1.size(),-1));

        long long ans2 = fun(v1,v2,1,0);

        return max(ans1,ans2);

    }
};