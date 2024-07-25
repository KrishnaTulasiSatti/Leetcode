class Solution {
public:
  void merge(vector<int> & arr,int l , int m , int h) {
     int i = l ;
     int j = m+1;
     int res[h-l+1];
     int k = 0;
     while(i <= m && j <= h) {
        if(arr[i] < arr[j])  res[k++] = arr[i++];
        else res[k++] = arr[j++];
        
     }
     while(i <= m)  res[k++] = arr[i++];
     while(j <= h) res[k++] = arr[j++];
     k = 0;
     for(int i = l ; i <= h ; i++) {
        arr[i] = res[k++];
     }
  }


  void mergeSort(vector<int>& nums,int l , int h) {
     if(l < h) {
        int m = (l+h)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,h);
        merge(nums,l,m,h);
     }
  }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};