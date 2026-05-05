class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;

        for(auto it : nums) {
            m[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        for(auto it : m) {
            pq.push({it.second,it.first});

            if(pq.size() > k) pq.pop();
        }

        vector<int>ans;

        while(!pq.empty()) {
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }

        return ans;


    }
};