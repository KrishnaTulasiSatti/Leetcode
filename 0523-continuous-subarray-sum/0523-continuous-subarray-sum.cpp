class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        if(nums.size() <= 1) return false;

        unordered_map<int,int>m;

        int sum = 0;

        for(int i = 0 ; i < nums.size() ; i++) {

            int temp = sum;

            if(i != 0) {
                m[temp % k]--;
                if(m[temp % k] == 0) m.erase(temp % k);
            }

            sum += nums[i];

            if(m.find(sum % k) != m.end()) {
                //cout << m[sum % k] << endl;
                return true;
            }

            m[temp % k]++;
            m[sum % k]++;
        }

        return false;
    }
};