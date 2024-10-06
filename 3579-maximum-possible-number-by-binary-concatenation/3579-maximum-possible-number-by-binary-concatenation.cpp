class Solution {
public:
static bool cmp(const string &a,const string &b) {
    if(a[0] == b[0]) return a+b > b+a;
    else return a[0] > b[0];
}
    int maxGoodNumber(vector<int>& nums) {
        vector<string>s;
        for(auto it : nums) {
            int n = it;
            string b = "";
            while(n) {
               b+=((n%2)+'0');
               n/=2;
            }
            reverse(b.begin(),b.end());
            s.push_back(b);
        }
        sort(s.begin(),s.end(),cmp);
        string finalAns = "";
        for(auto it : s) finalAns+=it;
        long long ans = 0;
        int j = 0;
        for(int i = finalAns.size()-1 ; i >= 0 ; i--) {
            //cout<<finalAns[i]<<" ";
            ans= ans+(finalAns[i]-'0')*pow(2,j);
            j++;
        }
       // cout<<finalAns;
        return ans;
    }
};