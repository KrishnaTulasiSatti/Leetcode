class Solution {
public:
static bool cmp(const pair<long long,long long> &a , const pair<long long,long long> &b) {
   if(a.second == b.second) return false;
    return a.second < b.second;
}
long long convertInteger(string n) {
    long long res = 0;
    int l = n.size()-1;
    for(int i = 0 ; i < n.size() ; i++) {
        res+= (n[i]-'0')*pow(10,l);
        l--;
    }
    return res;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long,long long>>v;
        for(int i = 0 ; i < nums.size() ; i++) {
            string number = to_string(nums[i]);
            string newnum = "";
            for(int j = 0 ; j < number.size() ; j++) {
              if(newnum == "" && mapping[number[j]-'0'] == 0) continue;
              else newnum+=mapping[number[j]-'0']+'0';
            }
            long long res = convertInteger(newnum);
            v.push_back(make_pair(nums[i],res));
        }
        sort(v.begin(),v.end(),cmp);   
        vector<int>ans;
        for(int i = 0 ; i < v.size() ; i++) ans.push_back(v[i].first);
        return ans;
    }
};