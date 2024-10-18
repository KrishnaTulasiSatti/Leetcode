class Solution {
public:
int fun(int n) {
    if(n == 1) return 0;
    if(n % 2) return 1+fun(3*n+1);
    else return 1+fun(n/2);
}
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>power;
        for(int i = lo ; i <= hi ; i++) {
            int p = fun(i);
            power.push_back({p,i});
        }
      // for(auto it : power) cout<<it.first<<" "<<it.second<<endl;
        sort(power.begin(),power.end());
        return power[k-1].second;

    }
};