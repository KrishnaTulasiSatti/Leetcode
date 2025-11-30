class Solution {
public:
    int reverse(int num) {
        int r = 0;
        while(num > 0) {
            int ld = num % 10;
            r =  r*10+ld;
            num/=10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int mini = INT_MAX;

        unordered_map<int,int>m;

        for(int i = 0 ; i < nums.size() ; i++) {

            int reverseNum = reverse(nums[i]);
        
            if(m.find(nums[i]) != m.end()) {
                mini = min(mini,abs(m[nums[i]]-i));
            }


            m[reverseNum] = i;
            
        }

        if(mini == INT_MAX) return -1;
        return mini;
    }
};