class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        map<int,int>mp;

        for(auto& it : flowers) {
            int start = it[0];
            int end = it[1];

            mp[start] += 1;
            mp[end+1] -= 1;
        }


        vector<pair<int,int>>v;

        for(auto& it : mp) {
            v.push_back({it.first,it.second});
        }

        for(int i = 1 ; i < v.size() ; i++) {
            v[i].second += v[i-1].second;
        }

        // for(auto& it : v) {
        //     cout << it.first << " " << it.second << endl;
        // }

        vector<int>ans;

        for(int i = 0 ; i < people.size() ; i++) {
        
            int ub = upper_bound(v.begin(),v.end(),make_pair(people[i],INT_MAX)) - v.begin();
            if(ub == 0) ans.push_back(0);
            else ans.push_back(v[ub-1].second);
            
        }

        return ans;
    }
};