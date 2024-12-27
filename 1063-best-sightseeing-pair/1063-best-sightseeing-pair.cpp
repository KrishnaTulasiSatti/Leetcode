class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        priority_queue<int>pq;
        int maxi = INT_MIN;
        for(int i = 0 ; i < values.size() ; i++) {
            if(pq.empty()) {
                pq.push(values[i]+i);
               
            }
            else{
                 maxi = max(maxi,pq.top()+values[i]-i);
                 pq.push(values[i]+i);
            }
        }
        return maxi;

    
    }
};