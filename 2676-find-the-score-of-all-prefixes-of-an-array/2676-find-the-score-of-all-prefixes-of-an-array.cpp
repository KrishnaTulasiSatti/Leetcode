class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        priority_queue<int>pq;
        vector<long long>scores;
        for(int i = 0 ; i <  nums.size() ; i++) {
            pq.push(nums[i]);
            scores.push_back(nums[i]+pq.top());
        }
        for(int i = 1 ; i < scores.size() ; i++) {
            scores[i]+=scores[i-1];
        }
        return scores;
    }
};