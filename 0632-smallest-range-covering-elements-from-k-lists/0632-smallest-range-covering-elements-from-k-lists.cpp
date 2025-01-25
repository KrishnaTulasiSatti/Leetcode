class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<pair<int,int>,int>>s;
        for(int i = 0 ; i < nums.size() ; i++) {
            s.insert({{nums[i][0],0},i});
        }
        auto sm = *s.begin();
        auto l = *s.rbegin();
        
        int mini = sm.first.first;
        int maxi = l.first.first;
        
        vector<int>v(2);
        v[0] = mini;
        v[1] = maxi;
        
        vector<int>ind(nums.size());

        for(int i = 0 ; i < nums.size() ; i++) {
            ind[i] = (nums[i].size());
        }
        while(true) {
            auto temp = *s.begin();
            int a = temp.second;
            int b = temp.first.second;
           // cout<<ind[a]<<" "<<b<<endl;
            if(b == ind[a]) break;
            
            s.erase(s.find(temp));
            s.insert({{nums[a][b++],b},a});
            // for(auto it : s) {
            //     cout<<it.first.first<<" "<<it.first.second;
            // }
            // cout<<endl;
            sm = *s.begin();
            l = *s.rbegin();

            int mini = sm.first.first;
            int maxi = l.first.first;
          //  cout<<mini<<" "<<maxi<<endl;
            if(maxi-mini < v[1]-v[0]) {
                v[0] = mini;
                v[1] = maxi;
            }


        }

        return v;

        
    }
};