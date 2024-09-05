class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        sum = accumulate(rolls.begin(),rolls.end(),sum);
        int total = rolls.size()+n;
        int res = (mean*total)-sum;
        //if(res == sum && rolls.size() == n) return {};
        vector<int>m;
        int i = res/n;
        int temp = n;
        while(temp--) {
            if(i <= 6) m.push_back(i);
            else return {};
        }
        cout<<res<<" "<<n<<endl;
        if(res % n != 0) {
            int s1 = accumulate(m.begin(),m.end(),0);
            cout<<s1<<endl;
            int j = m.size()-1;
            int mod = res % n;
            while(mod != 0 && j >= 0)  {
                if(m[j] == 6) {
                    j--;
                    continue;
                }
                else{
                    int t = mod;
                    if(m[j] < 6) {
                        int c = m[j];
                        m[j]+=mod;
                        if(m[j] > 6) {
                            m[j] = 6;
                            mod-=(6-c);
                            j--;
                        }
                        else mod = 0;
                        
                    }
                }
            }
            if(j < 0) return {};
        }
        for(auto it : m) {
            if(it < 1 || it > 6) return {};
        }
        return m;
    }
};