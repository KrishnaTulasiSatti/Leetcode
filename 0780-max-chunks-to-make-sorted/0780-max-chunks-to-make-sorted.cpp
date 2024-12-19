class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int sum1 = 0;
        int sum2 = 0;

        int cnt = 0;

        for(int i = 0 ; i < arr.size() ; i++) {
            sum1+=arr[i];
            sum2+=i;

            if(sum1 == sum2) cnt++;
        }
        
        return cnt;
       
    }
};