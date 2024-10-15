class Solution {
public:
    long long minimumSteps(string s) {
        vector<int>indOne;
        vector<int>indZero;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '1') indOne.push_back(i);
            else indZero.push_back(i);
        }
        int n = s.size()-1;
        long long cnt1 = 0;
        for(int i = indOne.size()-1 ; i >= 0 ; i--) {
            int a = indOne[i];
            cnt1+=(abs(a-n));
            n--;
        }
       // cout<<cnt1<<endl;
        long long cnt2 = 0;
        int m = 0;
        for(int i = 0 ; i < indZero.size() ; i++) {
            int b = indZero[i];
            cnt2+=(abs(b-m));
            m++;
        }
        long long ans = min(cnt1,cnt2);
        return ans;
    }
};