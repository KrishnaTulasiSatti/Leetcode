class Solution {
public:

    string fun(int i) {
        if(i == 1) return "0";

        string res = fun(i-1);

        res += "1";

        int n = res.size();

        for(int i = 0 ; i < n-1 ; i++) {
            if(res[i] == '1') res += "0";
            else res += "1";
        }

        reverse(res.begin()+n,res.end());

        return res;


    }
    char findKthBit(int n, int k) {
        string ans = fun(n);
        // cout << ans << endl;
        return ans[k-1];
    }
};