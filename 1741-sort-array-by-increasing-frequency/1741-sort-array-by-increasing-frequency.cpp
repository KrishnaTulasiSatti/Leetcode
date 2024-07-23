class Solution {
public:
    static bool cmp(const pair<int,int>&a , const pair<int,int>&b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
       map<int,int>m;
       for(int i = 0 ; i < nums.size() ; i++) m[nums[i]]++;
       vector<pair<int,int>>vec(m.begin(),m.end());
       sort(vec.begin(),vec.end(),cmp);
       vector<int>ans;
       for(auto it : vec) {
          for(int i = 0 ; i < it.second ; i++) ans.push_back(it.first);
       }
       return ans;
    } 
};