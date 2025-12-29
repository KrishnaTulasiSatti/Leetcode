class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        if(n < m) return findMedianSortedArrays(nums2,nums1);

        int low = 0;
        int high = m;


        int cnt = (m+n+1)/2;

        while(low <= high) {

            int mid1 = (low + high)/2;

            int mid2 = cnt-mid1;

          //  cout << mid1 << "--" << mid2 << endl;

            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;

            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];

            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];

         //   cout << l1 << " " << l2 << "-->" << r1 << " " << r2 << endl;

            if(l1 <= r2 && l2 <= r1) {
                if((m+n) % 2) return max(l1,l2)*1.0;
                else return (double)((max(l1,l2)+min(r1,r2))/2.0);
            }
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }

        return -1;
    }
};