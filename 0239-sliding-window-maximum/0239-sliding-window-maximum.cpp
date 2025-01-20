class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int>res;
        // set<pair<int,int>>s;

        // for(int i = 0 ; i < k ; i++) {
        //     s.insert({nums[i],i});
        // }

        // res.push_back(s.rbegin()->first);

        // for(int i = k ; i < nums.size() ; i++) {
        //     s.erase({nums[i-k],i-k});
        //     s.insert({nums[i],i});
        //     res.push_back(s.rbegin()->first);
        // }
        // // Since set stores in sorted order , we can simply access the last element
        // //   s.rbegin() and the first element by s.begin(), but we have to use the 
        // //   set<pair<int,int>> for handling duplicates 
        // return res;


        // O(n * log k)


        // Can be reduced by using deque

        vector<int>res;
        deque<int>dq;

        for(int i = 0 ; i < k ; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        
        for(int i = k ; i < nums.size() ; i++) {
            if(i-k == dq.front()) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
        
    }
};