class Solution {
public:
    int clumsy(int n) {

        if(n <= 2) return n;

        int ans = 0;

        int p = 1,d = 0,a = 0;

        ans += (n*(n-1))/(n-2);
        n-=3;
        ans += n;
        n--;

        int curr_pro = n;
        n--;
        while(n > 0) {

            if(p == 1) {
                if(curr_pro == 2) cout << n << endl; 
                curr_pro *= n;
                p = 0;
                d = 1;
            }
            else if(d == 1) {
                curr_pro /= n;
                d = 0;
                a = 1;
            }
            else if(a == 1) {
                ans -= curr_pro;
                curr_pro = n-1;
                ans += n;
                // cout << curr_pro << " " << ans  << " " << n << endl;
                p = 1;
                a = 0;
                n--;
            }
            n--;

        }

        // cout << curr_pro << endl;

        if(curr_pro >= 0) ans -= curr_pro;
        
        return ans;
    }
};