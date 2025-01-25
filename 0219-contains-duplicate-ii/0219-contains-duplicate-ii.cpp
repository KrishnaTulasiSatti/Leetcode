class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        set<pair<int,int>>s;

        for(int i = 0 ; i < nums.size() ; i++) {
            s.insert({nums[i],i});
        }

        while(!s.empty()) {
            auto t1 = *s.begin();
            cout<<t1.first<<" ";
            s.erase(t1);
            auto t2 = *s.begin();
            cout<<t2.first<<endl;
            int ind1 = t1.second;
            int ind2 = t2.second;
            cout<<ind1<<" "<<ind2<<endl;
            if(ind1 == ind2) break;
            if(t1.first == t2.first && abs(ind1-ind2) <= k) {
                return true;
            }
        }

        return false;

    }
};