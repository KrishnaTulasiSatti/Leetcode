class Solution {
public:
int fun(int n) {
    if(n == 1) return 0;
    if(n % 2) return 1+fun(n*3+1);
    return 1+fun(n/2);
     
}
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        for(int i = lo ; i <= hi ; i++) {
            v.push_back({fun(i),i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};