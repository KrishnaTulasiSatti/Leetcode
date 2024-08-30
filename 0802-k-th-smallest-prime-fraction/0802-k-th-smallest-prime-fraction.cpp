class Solution {
public:
static bool cmp(const pair<vector<int>,double>&a,const pair<vector<int>,double>&b) {
    return a.second < b.second;
}
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<vector<int>,double>>v;
        for(int i = 0 ; i < arr.size() ; i++) {
            for(int j = i+1 ; j < arr.size() ; j++) {
                vector<int>a(2);
                a[0] = arr[i];
                a[1] = arr[j];
                v.push_back({a,arr[i]*1.0/arr[j]});
            }
        }
        sort(v.begin(),v.end(),cmp);
        int c = 1;
        for(auto it : v) {
            if(c == k) return {it.first[0],it.first[1]};
            c++;
        }
        return {};
    }
};