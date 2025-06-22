class Solution {
public:
    int minSwaps(vector<int>& nums) {
        

        vector<int>odd;
        vector<int>even;

       for(int i = 0 ; i < nums.size() ; i++) {
           if(nums[i] % 2) odd.push_back(i);
           else even.push_back(i);
       }

        vector<int>res;

        int i = 0;
        int j = 0;
        
        while(i < odd.size() && j < even.size()) {
            
            res.push_back(even[j++]);
            res.push_back(odd[i++]);
            
        }

        if(i < odd.size()) res.push_back(odd[i++]);
        if(j < even.size()) res.push_back(even[j++]);

        if(i < odd.size() || j < even.size()) return -1;

        long long diff1 = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            diff1 += abs(i-res[i]);
        }        

        diff1 = diff1/2;

        vector<int>res2;

        i = 0;
        j = 0;

        while(i < odd.size() && j < even.size()) {
            
         
            res2.push_back(odd[i++]);
            res2.push_back(even[j++]);
            
        }

        if(i < odd.size()) res2.push_back(odd[i++]);
        if(j < even.size()) res2.push_back(even[j++]);

        if(i < odd.size() || j < even.size()) return -1;

        long long diff2 = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            diff2 += abs(i-res2[i]);
        }        

        diff2 = diff2/2;

        if(odd.size() > even.size()) return diff2;
        else if(even.size() > odd.size()) return diff1;
        else return min(diff1,diff2);
    }
};