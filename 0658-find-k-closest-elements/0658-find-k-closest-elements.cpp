class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int lb = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        
        int i = lb;
        int j = lb;

        vector<int>res;

        if(lb != arr.size() && arr[lb] != x) i = lb-1;
        else{
            if(lb != arr.size() && arr[lb] == x )res.push_back(x);
            i = lb-1;
            j = lb+1;
        }
        

        while(i >= 0 && j < arr.size() && res.size() < k) {
            int diff1 = x-arr[i];
            int diff2 = arr[j]-x;

            // cout << diff1 << " " << diff2 << endl;

            if(diff1 <= diff2) {
                res.push_back(arr[i]);
                i--;
            }
            else {
                res.push_back(arr[j]);
                j++;
            }
        } 

        while(i >= 0 && res.size() < k) {
            res.push_back(arr[i--]);
        }

        while(j < arr.size() && res.size() < k) {
            res.push_back(arr[j++]);
        }

        sort(res.begin(),res.end());

        return res;
    }
};