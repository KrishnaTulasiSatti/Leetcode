class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int>pq;
        long long score = 0;
        for(auto it : nums) pq.push(it);

        for(int i = 0 ; i < k ; i++) {
            int a = pq.top();
            pq.pop();
            score+=a;
            int c = a/3;
            if(a % 3) c = c+1;
            pq.push(c);
        }
        return score;
    }
};