class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>m;
        int k = 1;
        for(int i = 0 ; i < temp.size() ; i++) {
            if(m[temp[i]] != 0) continue;
            else m[temp[i]] = k++;
        }
        vector<int>ans;
        for(int i = 0 ; i < arr.size() ; i++) {
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }
};