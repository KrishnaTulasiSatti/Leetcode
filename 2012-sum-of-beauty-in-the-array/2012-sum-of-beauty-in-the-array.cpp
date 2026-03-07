class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int sum = 0;

        multiset<int>s1;
        s1.insert(nums[0]);
        multiset<int>s2;

        for(int i = 2 ; i < nums.size() ; i++) s2.insert(nums[i]);

        for(int i = 1 ; i < nums.size()-1 ; i++) {
            int left = *s1.rbegin();
            int right = *s2.begin();

            
            if(left < nums[i] && nums[i] < right) sum += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) sum += 1;
            
            // cout << left << " " << nums[i] << " " << right << "--" << sum << endl;
            s1.insert(nums[i]);
            s2.erase(s2.find(nums[i+1]));
        }

        return sum;


    }
};