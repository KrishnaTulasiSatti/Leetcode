class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>people;
        for(int i = 0 ; i < heights.size() ; i++) {
            people[heights[i]] = names[i];
        }
        vector<string>ans;
        for(auto it : people) {
          //  cout<<it.first<<" "<<it.second<<endl;
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};